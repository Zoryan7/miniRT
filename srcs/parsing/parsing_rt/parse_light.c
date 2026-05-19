/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:21:49 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:01:33 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_parse_coord_light(char *line, t_light_info *light, int *i)
{
	if (ft_recup_float(line, &light->light.coord.x, i, 0)
		|| ft_recup_float(line, &light->light.coord.y, i, 1)
		|| ft_recup_float(line, &light->light.coord.z, i, 2))
		return (1);
	return (0);
}

int	ft_parse_color_light(char *line, t_light_info *light, int *i)
{
	float	dest;
	char	color[5];

	if (ft_recup_color(color, line, i, 0))
		return (1);
	if (ft_char_to_color(&dest, color))
		return (1);
	light->light.color.r = dest;
	if (ft_recup_color(color, line, i, 1))
		return (1);
	if (ft_char_to_color(&dest, color))
		return (1);
	light->light.color.g = dest;
	if (ft_recup_color(color, line, i, 2))
		return (1);
	if (ft_char_to_color(&dest, color))
		return (1);
	light->light.color.b = dest;
	return (0);
}

static int	ft_parse_light_primary(int *i, char *line, t_light_info *dest)
{
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_parse_coord_light(line, dest, i))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_parse_brightness_light(line, dest, i))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_parse_color_light(line, dest, i))
		return (1);
	if (ft_skip_space(i, line, 1))
		return (1);
	return (0);
}

int	ft_parse_light(char *line, t_parsing *parsing)
{
	int				i;
	t_light_info	*dest;

	i = 1;
	dest = ft_new_light();
	if (!dest || ft_parse_light_primary(&i, line, dest))
		return (1);
	if (line[i] && line[i] != '\n')
	{
		if (ft_recup_float(line, &dest->light.radius, &i, 3)
			|| dest->light.radius < 0)
			return (1);
		if (ft_skip_space(&i, line, 1))
			return (1);
		if (line[i] && line[i] != '\n' && ft_parse_texture_bump(line,
				&dest->light.id_texture, &dest->light.id_bump, &i))
			return (1);
		if (ft_skip_space(&i, line, 1))
			return (1);
	}
	if (line[i] && line[i] != '\n')
		return (1);
	ft_add_back_light(dest, parsing);
	return (0);
}
