/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_sphere_json.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:47:18 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:20:04 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_add_value_to_key_sphere(t_object_info *dest, char *key, char *value,
		t_texture_list *textures)
{
	float	v;

	if (ft_cmp_key(key, "\"radius\"", 1) == 0)
	{
		if (ft_parse_single_float(value,
				&dest->object.specificites.sphere.radius, "radius"))
			return (1);
		v = dest->object.specificites.sphere.radius * 2.0f;
		dest->object.specificites.sphere.diameter = v;
		return (0);
	}
	if (ft_cmp_key(key, "\"diameter\"", 1) == 0)
	{
		if (ft_parse_single_float(value,
				&dest->object.specificites.sphere.diameter, "diameter"))
			return (1);
		v = dest->object.specificites.sphere.diameter * 0.5f;
		dest->object.specificites.sphere.radius = v;
		return (0);
	}
	return (ft_add_value_to_key_object(textures, dest, key, value));
}

int	ft_parse_sphere_json(t_parsing *parsing, int fd)
{
	int				i;
	t_object_info	*dest;
	char			*line;
	char			*key;
	char			*value;

	dest = ft_new_object_json(0);
	if (!dest || ft_check_in_out_object(ft_get_next_line_parsing(fd), 0))
		return (1);
	line = ft_get_next_line_parsing(fd);
	while (line && ft_check_in_out_object(line, 2))
	{
		i = 0;
		if (ft_skip_space(&i, line, 0) || ft_split_value_key(line + i, &key,
				&value) || ft_add_value_to_key_sphere(dest, key, value,
				&parsing->texture))
			return (1);
		line = ft_get_next_line_parsing(fd);
	}
	if (ft_check_in_out_object(line, 1) || ft_check_good_values_object(dest))
		return (1);
	ft_add_back_object(dest, parsing);
	return (0);
}
