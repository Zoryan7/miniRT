/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_json.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:50:11 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/13 14:05:41 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_add_value_to_key_ambient(t_mini_rt *rt, char *key, char *value)
{
	if (ft_cmp_key(key, "\"color\"", 1) == 0)
		return (ft_parse_color(value, &rt->ambient.color));
	if (ft_cmp_key(key, "\"color 2\"", 1) == 0)
		return (ft_parse_color(value, &rt->ambient.color_2));
	else if (ft_cmp_key(key, "\"brightness\"", 1) == 0)
		return (ft_ratio_positive(&rt->ambient.brightness, "brightness",
				value));
	else
		return (1);
}

int	ft_parse_ambient_json(t_mini_rt *rt, t_parsing *parsing, int fd)
{
	int		i;
	char	*key;
	char	*value;
	char	*line;

	if (parsing->ambient != 0)
		return (ft_putstr_fd("to many ambient light", 2), 1);
	parsing->ambient++;
	if (ft_check_in_out_object(ft_get_next_line_parsing(fd), 0))
		return (1);
	line = ft_get_next_line_parsing(fd);
	while (line && ft_check_in_out_object(line, 2))
	{
		i = 0;
		if (ft_skip_space(&i, line, 0) || ft_split_value_key(line + i, &key,
				&value) || ft_add_value_to_key_ambient(rt, key, value))
			return (1);
		line = ft_get_next_line_parsing(fd);
	}
	if (ft_check_in_out_object(line, 1))
		return (1);
	return (0);
}
