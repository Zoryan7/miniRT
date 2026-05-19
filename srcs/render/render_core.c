/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 05:40:51 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 05:41:11 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_draw_thread(t_mini_rt *rt, t_task task)
{
	t_vec	target;
	t_ray	ray;
	t_vec	color;
	t_vec	pix_color;

	while (task.x < rt->info.width && rt->nb_img < 10000)
	{
		target = rt->camera.view_origin;
		target.v = target.v + rt->camera.delta_u.v * (float)task.x
			+ rt->camera.delta_u.v * rt->camera.rand_x;
		target.v = target.v + rt->camera.delta_v.v * (float)task.y
			+ rt->camera.delta_v.v * rt->camera.rand_y;
		ray.origin = rt->camera.coord;
		ray.destination = target;
		ray.direction = ft_vec_normalize(ft_vec_sub(ray.destination,
					ray.origin));
		ray.r_direction = ft_vec_divide_vec((t_vec){{1.0f, 1.0f, 1.0f}},
				ray.direction);
		ray.eta = rt->camera.eta;
		color = ft_calcul_color(rt, ray, rt->info.bounce, task);
		pix_color = ft_get_pixel_2(rt, task.x, task.y, color);
		ft_put_pixel(rt, task.x, task.y, pix_color);
		task.x++;
	}
}

void	ft_calcul_viewport(t_mini_rt *rt)
{
	float	ratio;
	float	theta;

	if (rt->nb_img == 0)
		rt->camera.eta = ft_determine_eta(rt, rt->camera.coord);
	ratio = (float)rt->info.height / (float)rt->info.width;
	theta = (float)rt->camera.fov * M_PI / 180;
	rt->camera.view_width = tanf(theta * 0.5);
	rt->camera.view_height = rt->camera.view_width * (ratio);
	rt->camera.view_u = ft_vec_scale(rt->camera.right, rt->camera.view_width);
	rt->camera.view_v = ft_vec_scale(ft_vec_scale(rt->camera.up,
				rt->camera.view_height), -1);
	rt->camera.delta_u.v = rt->camera.view_u.v / (float)rt->info.width;
	rt->camera.delta_v.v = rt->camera.view_v.v / (float)rt->info.height;
	rt->camera.view_origin.v = rt->camera.coord.v + rt->camera.forward.v
		- rt->camera.view_u.v * 0.5f - rt->camera.view_v.v * 0.5f;
}

float	ft_determine_eta(t_mini_rt *rt, t_vec point)
{
	int		i;
	float	min;
	int		i_min;
	float	dist;

	i = 0;
	min = INFINITY;
	i_min = 0;
	while (i < rt->size_object)
	{
		dist = ft_choose_point(rt->object[i], point);
		if (dist < min)
		{
			min = dist;
			i_min = i;
		}
		i++;
	}
	if (min == INFINITY)
		return (1.0f);
	else
		return (rt->object[i_min].refraction_indice);
}
