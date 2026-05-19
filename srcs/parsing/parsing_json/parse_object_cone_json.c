/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_cone_json.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:31:58 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 02:56:31 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_add_value_to_key_cone_2(t_object_info *dest, char *key, char *value,
		t_texture_list *textures)
{
	float	diameter;

	if (ft_cmp_key(key, "\"diameter\"", 1) == 0)
	{
		if (ft_parse_single_float(value,
				&dest->object.specificites.cone.diameter, "diameter"))
			return (1);
		diameter = dest->object.specificites.cone.diameter * 0.5f;
		dest->object.specificites.cone.radius = diameter;
		return (0);
	}
	if (ft_cmp_key(key, "\"height\"", 1) == 0)
		return (ft_parse_single_float(value,
				&dest->object.specificites.cone.height, "height"));
	return (ft_add_value_to_key_object(textures, dest, key, value));
}

int	ft_add_value_to_key_cone(t_object_info *dest, char *key, char *value,
		t_texture_list *textures)
{
	float	diameter;

	if (ft_cmp_key(key, "\"normal\"", 1) == 0)
	{
		if (ft_parse_coordinates(value, &dest->object.vec))
			return (1);
		return (ft_check_normalize(dest->object.vec));
	}
	if (ft_cmp_key(key, "\"radius\"", 1) == 0)
	{
		if (ft_parse_single_float(value, &dest->object.specificites.cone.radius,
				"radius"))
			return (1);
		diameter = dest->object.specificites.cone.radius * 2.0f;
		dest->object.specificites.cone.diameter = diameter;
		return (0);
	}
	return (ft_add_value_to_key_cone_2(dest, key, value, textures));
}

int	ft_parse_cone_json(t_parsing *parsing, int fd)
{
	int				i;
	char			*line;
	char			*key;
	char			*value;
	t_object_info	*dest;

	dest = ft_new_object_json(1);
	if (!dest || ft_check_in_out_object(ft_get_next_line_parsing(fd), 0))
		return (1);
	line = ft_get_next_line_parsing(fd);
	while (line && ft_check_in_out_object(line, 2))
	{
		i = 0;
		if (ft_skip_space(&i, line, 0) || ft_split_value_key(line + i, &key,
				&value) || ft_add_value_to_key_cone(dest, key, value,
				&parsing->texture))
			return (1);
		line = ft_get_next_line_parsing(fd);
	}
	if (ft_check_in_out_object(line, 1) || ft_check_good_values_object(dest))
		return (1);
	ft_add_back_object(dest, parsing);
	return (0);
}
