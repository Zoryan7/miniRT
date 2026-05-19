/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcorner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 10:26:59 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:36:49 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_init_info2(t_calcul_color *info2)
{
	info2->touch = 0;
	info2->i = 0;
	info2->j_obj = -1;
	info2->dist_obj = INFINITY;
	info2->ind_obj = __INT_MAX__;
}

static int	ft_check_sky(t_mini_rt *rt, t_task task, t_vec2 ya)
{
	t_vec2			inter;
	t_ray			test_ray;
	t_vec			target;
	t_calcul_color	info2;

	ft_init_info2(&info2);
	target = rt->camera.view_origin;
	target.v = target.v + rt->camera.delta_u.v * (float)task.x
		+ rt->camera.delta_u.v * ya.x;
	target.v = target.v + rt->camera.delta_v.v * (float)task.y
		+ rt->camera.delta_v.v * ya.y;
	test_ray.destination = target;
	test_ray.origin = rt->camera.coord;
	test_ray.direction = ft_vec_normalize(ft_vec_sub(test_ray.destination,
				test_ray.origin));
	test_ray.r_direction = ft_vec_divide_vec((t_vec){{1.0f, 1.0f, 1.0f}},
			test_ray.direction);
	while (info2.i < rt->size_object && rt->object[info2.i].type == plane)
	{
		inter = ft_choose_intersect(rt->object[info2.i], test_ray);
		ft_inter_choice(&info2, inter);
	}
	inter = ft_intersect_bvh(test_ray, rt->bvh, rt, &info2);
	return (info2.dist_obj == INFINITY);
}

static int	ft_check_obj(t_mini_rt *rt, t_task task, t_vec2 ya,
		t_calcul_color info)
{
	t_vec2			inter;
	t_ray			test_ray;
	t_vec			target;
	t_calcul_color	info2;

	ft_init_info2(&info2);
	target = rt->camera.view_origin;
	target.v = target.v + rt->camera.delta_u.v * (float)task.x
		+ rt->camera.delta_u.v * ya.x;
	target.v = target.v + rt->camera.delta_v.v * (float)task.y
		+ rt->camera.delta_v.v * ya.y;
	test_ray.destination = target;
	test_ray.origin = rt->camera.coord;
	test_ray.direction = ft_vec_normalize(ft_vec_sub(test_ray.destination,
				test_ray.origin));
	test_ray.r_direction = ft_vec_divide_vec((t_vec){{1.0f, 1.0f, 1.0f}},
			test_ray.direction);
	while (info2.i < rt->size_object && rt->object[info2.i].type == plane)
	{
		inter = ft_choose_intersect(rt->object[info2.i], test_ray);
		ft_inter_choice(&info2, inter);
	}
	inter = ft_intersect_bvh(test_ray, rt->bvh, rt, &info2);
	return (info2.ind_obj == info.ind_obj);
}

int	ft_check_corner_pix_sky(t_mini_rt *rt, t_task task)
{
	if (!ft_check_sky(rt, task, (t_vec2){{0, 0}}))
		return (0);
	if (!ft_check_sky(rt, task, (t_vec2){{1, 1}}))
		return (0);
	if (!ft_check_sky(rt, task, (t_vec2){{1, 0}}))
		return (0);
	if (!ft_check_sky(rt, task, (t_vec2){{0, 1}}))
		return (0);
	return (1);
}

int	ft_check_corner_pix_obj(t_mini_rt *rt, t_calcul_color info, t_task task)
{
	if (!ft_check_obj(rt, task, (t_vec2){{0, 0}}, info))
		return (0);
	if (!ft_check_obj(rt, task, (t_vec2){{1, 1}}, info))
		return (0);
	if (!ft_check_obj(rt, task, (t_vec2){{1, 0}}, info))
		return (0);
	if (!ft_check_obj(rt, task, (t_vec2){{0, 1}}, info))
		return (0);
	return (1);
}
