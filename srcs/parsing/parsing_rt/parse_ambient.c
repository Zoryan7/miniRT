/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:19:14 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:41:02 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_parse_color_ambient(char *line, t_vec *col, int *i)
{
	float	dest;
	char	color[4];

	col->r = 0;
	if (ft_recup_color(color, line, i, 0))
		return (1);
	if (ft_char_to_color(&dest, color))
		return (1);
	col->r = dest;
	if (ft_recup_color(color, line, i, 1))
		return (1);
	if (ft_char_to_color(&dest, color))
		return (1);
	col->g = dest;
	if (ft_recup_color(color, line, i, 2))
		return (1);
	if (ft_char_to_color(&dest, color))
		return (1);
	col->b = dest;
	return (0);
}

int	ft_parse_ambient(char *line, t_mini_rt *rt, t_parsing *parsing)
{
	int	i;

	i = 1;
	if (parsing->ambient != 0)
		return (1);
	parsing->ambient++;
	if (ft_skip_space(&i, line, 0) || ft_parse_brightness_ambient(line, rt, &i))
		return (1);
	if (ft_skip_space(&i, line, 0))
		return (1);
	if (ft_parse_color_ambient(line, &rt->ambient.color, &i))
		return (1);
	if (ft_skip_space(&i, line, 1))
		return (1);
	if (line[i] && line[i] != '\n')
	{
		if (ft_parse_color_ambient(line, &rt->ambient.color_2, &i))
			return (1);
		if (ft_skip_space(&i, line, 1))
			return (1);
	}
	if (line[i] && line[i] != '\n')
		return (1);
	return (0);
}
