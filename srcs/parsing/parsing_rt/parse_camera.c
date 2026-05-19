/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:20:54 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 22:49:26 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_parse_coord_camera(char *line, t_mini_rt *rt, int *i)
{
	float	dest;

	if (ft_recup_float(line, &dest, i, 0))
		return (1);
	rt->camera.coord.x = dest;
	if (ft_recup_float(line, &dest, i, 1))
		return (1);
	rt->camera.coord.y = dest;
	if (ft_recup_float(line, &dest, i, 2))
		return (1);
	rt->camera.coord.z = dest;
	return (0);
}

int	ft_forward_camera(char *line, t_mini_rt *rt, int *i)
{
	if (ft_recup_float(line, &rt->camera.init_forward.x, i, 0)
		|| !(rt->camera.init_forward.x >= -1 && rt->camera.init_forward.x <= 1))
		return (1);
	if (ft_recup_float(line, &rt->camera.init_forward.y, i, 1)
		|| !(rt->camera.init_forward.y >= -1 && rt->camera.init_forward.y <= 1))
		return (1);
	if (ft_recup_float(line, &rt->camera.init_forward.z, i, 2)
		|| !(rt->camera.init_forward.z >= -1 && rt->camera.init_forward.z <= 1))
		return (1);
	rt->camera.forward = rt->camera.init_forward;
	return (0);
}

int	ft_parse_vec_camera(char *line, t_mini_rt *rt, int *i)
{
	rt->camera.up.x = 0;
	rt->camera.up.y = 1;
	rt->camera.up.z = 0;
	if (ft_forward_camera(line, rt, i))
		return (1);
	rt->camera.right = ft_vec_cross((t_vec){{0, 1, 0, 0}},
			rt->camera.init_forward);
	return (0);
}

int	ft_parse_fov_camera(char *line, t_mini_rt *rt, int *i)
{
	char	dest[5];

	if (ft_recup_color(dest, line, i, 2)
		|| ft_char_to_color_fov(&rt->camera.fov, dest) || !(rt->camera.fov > 0
			&& rt->camera.fov <= 180))
		return (1);
	return (0);
}

int	ft_parse_camera(char *line, t_mini_rt *rt, t_parsing *parsing)
{
	int	i;

	i = 1;
	if (parsing->camera != 0)
		return (1);
	parsing->camera++;
	rt->camera.focal_lenght = 1.0;
	if (ft_skip_space(&i, line, 0))
		return (1);
	if (ft_parse_coord_camera(line, rt, &i))
		return (1);
	if (ft_skip_space(&i, line, 0))
		return (1);
	if (ft_parse_vec_camera(line, rt, &i))
		return (1);
	if (ft_skip_space(&i, line, 0))
		return (1);
	if (ft_parse_fov_camera(line, rt, &i))
		return (1);
	if (ft_skip_space(&i, line, 1))
		return (1);
	if (line[i] && line[i] != '\n')
		return (1);
	return (0);
}
