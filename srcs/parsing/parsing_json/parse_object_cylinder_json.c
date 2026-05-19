/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_cylinder_json.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:15:19 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:33:59 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_add_value_to_key_cylinder(t_object_info *dest, char *key, char *value,
		t_texture_list *textures)
{
	if (ft_cmp_key(key, "\"normal\"", 1) == 0)
		return (ft_parse_coordinates(value, &dest->object.vec));
	if (ft_cmp_key(key, "\"radius\"", 1) == 0)
	{
		if (ft_parse_single_float(value,
				&dest->object.specificites.cylinder.radius, "radius"))
			return (1);
		dest->object.specificites.cylinder.diameter = ft_diameter(dest);
		return (0);
	}
	if (ft_cmp_key(key, "\"diameter\"", 1) == 0)
	{
		if (ft_parse_single_float(value,
				&dest->object.specificites.cylinder.diameter, "diameter"))
			return (1);
		dest->object.specificites.cylinder.radius = ft_radius(dest);
		return (0);
	}
	if (ft_cmp_key(key, "\"height\"", 1) == 0)
		return (ft_parse_single_float(value,
				&dest->object.specificites.cylinder.height, "height"));
	return (ft_add_value_to_key_object(textures, dest, key, value));
}

int	ft_parse_cylinder_json(t_parsing *parsing, int fd)
{
	int				i;
	t_object_info	*dest;
	char			*line;
	char			*key;
	char			*value;

	dest = ft_new_object_json(2);
	if (!dest)
		return (1);
	if (ft_check_in_out_object(ft_get_next_line_parsing(fd), 0))
		return (1);
	line = ft_get_next_line_parsing(fd);
	while (line && ft_check_in_out_object(line, 2))
	{
		i = 0;
		if (ft_skip_space(&i, line, 0) || ft_split_value_key(line + i, &key,
				&value) || ft_add_value_to_key_cylinder(dest, key, value,
				&parsing->texture))
			return (1);
		line = ft_get_next_line_parsing(fd);
	}
	if (ft_check_in_out_object(line, 1) || ft_check_good_values_object(dest))
		return (1);
	ft_add_back_object(dest, parsing);
	return (0);
}
