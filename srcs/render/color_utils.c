/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 05:18:41 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 05:27:23 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_vec	ft_gradient(t_vec color_a, t_vec color_b, float reflection)
{
	t_vec	new_color;

	new_color.v = color_a.v + (color_b.v - color_a.v) * reflection;
	return (new_color);
}

t_vec	ft_ambient_color(t_mini_rt *rt, t_ray ray, t_task task)
{
	float	dot;

	if (rt->opti_on == 1 && rt->nb_img > 2 && rt->first_hit[task.y
			* rt->info.width + task.x] == -1)
		return ((t_vec){{0, 255, 0}});
	dot = ft_vec_dot(ray.direction, (t_vec){{0, 1, 0, 0}});
	dot = (dot + 1) * 0.5;
	return (ft_gradient(rt->ambient.color_2, rt->ambient.color, dot));
}

t_vec	ft_tex_color(t_mini_rt *rt, float min, int i_min, t_ray ray)
{
	t_vec	hit_point;
	t_vec2	uv;

	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, min));
	uv = ft_uv_object(rt->object[i_min], hit_point);
	return (ft_get_pixel_3(rt->texture[rt->object[i_min].id_texture], uv.x,
			uv.y));
}
