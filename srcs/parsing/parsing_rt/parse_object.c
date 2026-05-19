/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:21:19 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 08:53:16 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_parse_specificities_object(char *line, t_object_info *dest, int object,
		int *i)
{
	if (object == 0 && ft_parse_sphere_specificities(line, dest, i))
		return (1);
	if (object == 1 && ft_parse_plane_specificities(line, dest, i))
		return (1);
	if (object == 2 && ft_parse_cylinder_specificities(line, dest, i))
		return (1);
	if (object == 3 && ft_parse_cone_specificities(line, dest, i))
		return (1);
	if (object == 4 && ft_parse_r_box_specificities(line, dest, i))
		return (1);
	if (object == 5 && ft_parse_triangle_specificities(line, dest, i))
		return (1);
	if (object == 6 && ft_parse_box_specificities(line, dest, i))
		return (1);
	return (0);
}

int	ft_parse_light_effect(char *line, t_object_info *dest, int *i)
{
	if (ft_recup_float(line, &dest->object.reflection, i, 2))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &dest->object.transparency, i, 2))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &dest->object.refraction_indice, i, 2))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &dest->object.randomless, i, 3))
		return (1);
	return (0);
}

int	ft_parse_texture_bump(char *line, int *id_texture, int *id_bump, int *i)
{
	char	t[5];

	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_color(t, line, i, 2))
		return (1);
	*id_texture = (ft_atoi(t) - 1);
	if (*id_texture < -1)
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_color(t, line, i, 2))
		return (1);
	*id_bump = (ft_atoi(t) - 1);
	if (*id_bump < -1)
		return (1);
	return (0);
}

static int	ft_parse_object_primary(char *line, t_object_info *dest, int object,
		int *i)
{
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_parse_coord_object(line, dest, i))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_parse_specificities_object(line, dest, object, i))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_parse_color_object(line, dest, i))
		return (1);
	return (0);
}

int	ft_parse_object(char *line, t_parsing *parsing, int object)
{
	int				i;
	t_object_info	*dest;

	i = 2;
	dest = ft_new_object();
	if (!dest || ft_parse_object_primary(line, dest, object, &i))
		return (1);
	if (ft_skip_space(&i, line, 1))
		return (1);
	if (line[i] && line[i] != '\n')
	{
		if (ft_parse_light_effect(line, dest, &i))
			return (1);
		if (ft_skip_space(&i, line, 1))
			return (1);
		if (line[i] && line[i] != '\n' && ft_parse_texture_bump(line,
				&dest->object.id_texture, &dest->object.id_bump, &i))
			return (1);
		if (ft_skip_space(&i, line, 1))
			return (1);
	}
	if (line[i] && line[i] != '\n')
		return (1);
	ft_add_back_object(dest, parsing);
	return (0);
}
