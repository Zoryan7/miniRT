/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_json.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:35:44 by ymoumene          #+#    #+#             */
/*   Updated: 2026/05/18 14:21:41 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_check_good_values_camera(t_mini_rt *rt)
{
	if (rt->camera.fov > 180)
		return (ft_putstr_fd("invalid fov in camera", 2), 1);
	if (rt->camera.forward.w == 0)
		return (ft_putstr_fd("no normal in camera", 2), 1);
	if (rt->camera.coord.w == 0)
		return (ft_putstr_fd("no coordinates in camera", 2), 1);
	return (0);
}

int	ft_add_value_to_key_camera(t_mini_rt *rt, char *key, char *value,
		int *nb_fov)
{
	if (ft_cmp_key(key, "\"coordinates\"", 1) == 0)
		return (ft_parse_coordinates(value, &rt->camera.coord));
	if (ft_cmp_key(key, "\"normal\"", 1) == 0)
	{
		if (ft_parse_normal(value, &rt->camera.forward))
			return (1);
		rt->camera.init_forward = rt->camera.forward;
		rt->camera.up.x = 0;
		rt->camera.up.y = 1;
		rt->camera.up.z = 0;
		rt->camera.right = ft_vec_cross(rt->camera.init_forward, rt->camera.up);
		return (0);
	}
	if (ft_cmp_key(key, "\"fov\"", 1) == 0)
		return (ft_parse_fov(value, &rt->camera.fov, nb_fov));
	return (0);
}

int	ft_parse_camera_json(t_mini_rt *rt, t_parsing *parsing, int fd)
{
	int		i;
	char	*line;
	char	*key;
	char	*value;

	if (parsing->camera != 0)
		return (ft_putstr_fd("to many camera", 2), 1);
	parsing->camera++;
	if (ft_check_in_out_object(ft_get_next_line_parsing(fd), 0))
		return (1);
	line = ft_get_next_line_parsing(fd);
	while (line && ft_check_in_out_object(line, 2))
	{
		i = 0;
		if (ft_skip_space(&i, line, 0) || ft_split_value_key(line + i, &key,
				&value) || ft_add_value_to_key_camera(rt, key, value,
				&parsing->fov))
			return (1);
		line = ft_get_next_line_parsing(fd);
	}
	if (ft_check_in_out_object(line, 1) || ft_check_good_values_camera(rt))
		return (1);
	return (0);
}
