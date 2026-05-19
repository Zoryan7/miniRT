/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_triangle_json.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:40:27 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:20:23 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_add_value_to_key_triangle(t_object_info *dest, char *key, char *value,
		t_texture_list *textures)
{
	if (ft_cmp_key(key, "\"point A\"", 1) == 0)
		return (ft_parse_coordinates(value, &dest->object.coord));
	if (ft_cmp_key(key, "\"point B\"", 1) == 0)
		return (ft_parse_coordinates(value,
				&dest->object.specificites.triangle.b));
	if (ft_cmp_key(key, "\"point C\"", 1) == 0)
		return (ft_parse_coordinates(value,
				&dest->object.specificites.triangle.c));
	return (ft_add_value_to_key_object(textures, dest, key, value));
}

int	ft_parse_triangle_json(t_parsing *parsing, int fd)
{
	int				i;
	t_object_info	*dest;
	char			*line;
	char			*key;
	char			*value;

	dest = ft_new_object_json(6);
	if (!dest || ft_check_in_out_object(ft_get_next_line_parsing(fd), 0))
		return (1);
	dest->object.type = triangle;
	line = ft_get_next_line_parsing(fd);
	while (line && ft_check_in_out_object(line, 2))
	{
		i = 0;
		if (ft_skip_space(&i, line, 0) || ft_split_value_key(line + i, &key,
				&value) || ft_add_value_to_key_triangle(dest, key, value,
				&parsing->texture))
			return (1);
		line = ft_get_next_line_parsing(fd);
	}
	if (ft_check_in_out_object(line, 1) || ft_check_good_values_object(dest))
		return (1);
	ft_add_back_object(dest, parsing);
	return (0);
}
