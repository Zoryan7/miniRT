/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_box_json.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:38:38 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:16:08 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_add_value_to_key_box_2(t_object_info *dest, char *key, char *value,
		t_texture_list *textures)
{
	if (ft_cmp_key(key, "\"width\"", 1) == 0)
	{
		if (ft_parse_single_float(value,
				&dest->object.specificites.box.aabb.max.x, "width"))
			return (1);
		dest->object.specificites.box.aabb.max.x += dest->object.coord.x;
		return (0);
	}
	if (ft_cmp_key(key, "\"depth\"", 1) == 0)
	{
		if (ft_parse_single_float(value,
				&dest->object.specificites.box.aabb.max.z, "depth"))
			return (1);
		dest->object.specificites.box.aabb.max.z += dest->object.coord.z;
		return (0);
	}
	return (ft_add_value_to_key_object(textures, dest, key, value));
}

int	ft_add_value_to_key_box(t_object_info *dest, char *key, char *value,
		t_texture_list *textures)
{
	if (ft_cmp_key(key, "\"normal\"", 1) == 0)
		return (ft_parse_coordinates(value, &dest->object.vec));
	if (ft_cmp_key(key, "\"coordinates\"", 1) == 0)
	{
		if (ft_parse_coordinates(value, &dest->object.coord))
			return (1);
		dest->object.specificites.box.aabb.min = dest->object.coord;
		return (0);
	}
	if (ft_cmp_key(key, "\"height\"", 1) == 0)
	{
		if (ft_parse_single_float(value,
				&dest->object.specificites.box.aabb.max.y, "height"))
			return (1);
		dest->object.specificites.box.aabb.max.y += dest->object.coord.y;
		return (0);
	}
	return (ft_add_value_to_key_box_2(dest, key, value, textures));
}

int	ft_parse_box_json(t_parsing *parsing, int fd)
{
	int				i;
	char			*line;
	char			*key;
	char			*value;
	t_object_info	*dest;

	key = NULL;
	value = NULL;
	dest = ft_new_object_json(4);
	if (!dest || ft_check_in_out_object(ft_get_next_line_parsing(fd), 0))
		return (1);
	line = ft_get_next_line_parsing(fd);
	while (line && ft_check_in_out_object(line, 2))
	{
		i = 0;
		if (ft_skip_space(&i, line, 0) || ft_split_value_key(line + i, &key,
				&value) || ft_add_value_to_key_box(dest, key, value,
				&parsing->texture))
			return (1);
		line = ft_get_next_line_parsing(fd);
	}
	if (ft_check_in_out_object(line, 1) || ft_check_good_values_object(dest))
		return (1);
	ft_add_back_object(dest, parsing);
	return (0);
}
