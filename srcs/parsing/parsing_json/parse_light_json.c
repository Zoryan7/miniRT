/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_json.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:06:13 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:22:42 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

t_light_info	*ft_initialize_light(void)
{
	t_light_info	*dest;

	dest = ft_new_light();
	if (!dest)
		return (NULL);
	dest->light.radius = -1;
	dest->light.brightness = -1;
	dest->light.color.t = 0;
	dest->light.coord.w = 0;
	return (dest);
}

int	ft_check_good_values_light(t_light_info *light)
{
	if (light->light.radius < 0 && light->light.radius != -1)
		return (ft_putstr_fd("invalid radius in light", 2), 1);
	if (light->light.radius == -1)
		light->light.radius = 0;
	if (light->light.brightness < 0)
		return (ft_putstr_fd("invalid brightness in light", 2), 1);
	if (light->light.color.t == 0)
		return (ft_putstr_fd("no color in light", 2), 1);
	if (light->light.coord.w == 0)
		return (ft_putstr_fd("no coordinates in light", 2), 1);
	return (0);
}

int	ft_add_value_to_key_light(t_texture_list *textures, t_light_info *light,
		char *key, char *value)
{
	if (ft_cmp_key(key, "\"coordinates\"", 1) == 0)
		return (ft_parse_coordinates(value, &light->light.coord));
	else if (ft_cmp_key(key, "\"color\"", 1) == 0)
		return (ft_parse_color(value, &light->light.color));
	else if (ft_cmp_key(key, "\"brightness\"", 1) == 0)
		return (ft_parse_ratio(value, &light->light.brightness, "brightness"));
	else if (ft_cmp_key(key, "\"radius\"", 1) == 0)
		return (ft_parse_single_float(value, &light->light.radius, "radius"));
	if (ft_cmp_key(key, "\"texture\"", 1) == 0)
		return (ft_parse_textures_json(textures, value,
				&light->light.id_texture, "texture"));
	if (ft_cmp_key(key, "\"bump_map\"", 1) == 0)
		return (ft_parse_textures_json(textures, value, &light->light.id_bump,
				"bump_map"));
	return (1);
}

int	ft_parse_light_json(t_parsing *parsing, int fd)
{
	int				i;
	char			*line;
	char			*key;
	char			*value;
	t_light_info	*dest;

	dest = ft_initialize_light();
	if (!dest)
		return (1);
	if (ft_check_in_out_object(ft_get_next_line_parsing(fd), 0))
		return (1);
	line = ft_get_next_line_parsing(fd);
	while (line && ft_check_in_out_object(line, 2))
	{
		i = 0;
		if (ft_skip_space(&i, line, 0) || ft_split_value_key(line + i, &key,
				&value) || ft_add_value_to_key_light(&parsing->texture, dest,
				key, value))
			return (1);
		line = ft_get_next_line_parsing(fd);
	}
	if (ft_check_in_out_object(line, 1) || ft_check_good_values_light(dest))
		return (1);
	ft_add_back_light(dest, parsing);
	return (0);
}
