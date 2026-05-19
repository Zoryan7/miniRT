/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_plane_json.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:36:29 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:24:16 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_add_value_to_key_plane(t_object_info *dest, char *key, char *value,
		t_texture_list *textures)
{
	if (ft_cmp_key(key, "\"normal\"", 1) == 0)
		return (ft_parse_normal(value, &dest->object.vec));
	return (ft_add_value_to_key_object(textures, dest, key, value));
}

int	ft_parse_plane_json(t_parsing *parsing, int fd)
{
	int				i;
	t_object_info	*dest;
	char			*line;
	char			*key;
	char			*value;

	dest = ft_new_object_json(5);
	if (!dest)
		return (1);
	if (ft_check_in_out_object(ft_get_next_line_parsing(fd), 0))
		return (1);
	line = ft_get_next_line_parsing(fd);
	while (line && ft_check_in_out_object(line, 2))
	{
		i = 0;
		if (ft_skip_space(&i, line, 0) || ft_split_value_key(line + i, &key,
				&value) || ft_add_value_to_key_plane(dest, key, value,
				&parsing->texture))
			return (1);
		line = ft_get_next_line_parsing(fd);
	}
	if (ft_check_in_out_object(line, 1) || ft_check_good_values_object(dest))
		return (1);
	ft_add_back_object(dest, parsing);
	return (0);
}
