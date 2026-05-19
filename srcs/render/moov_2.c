/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 10:53:36 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 11:49:07 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_moov_obj(t_mini_rt *rt, unsigned long elapsed)
{
	float	speed;
	t_vec	move;

	ft_has_to_moov(rt, &move);
	if (!move.x && !move.y && !move.z && !rt->move_on)
		return ;
	rt->nb_img = 0;
	ft_free_gc_type(bvh_type);
	rt->bvh = ft_bvh(rt);
	speed = rt->info.speed * (float)elapsed / 1e6;
	if (rt->object[rt->selec].type == triangle)
		ft_moov_obj_triangle(rt, speed, move);
	else if (rt->object[rt->selec].type == cone)
		ft_moov_obj_cone(rt, speed, move);
	else
		ft_moov_obj_obj(rt, speed, move);
	if (rt->object[rt->selec].type == lights)
		ft_moov_obj_light(rt, speed, move);
	if (rt->object[rt->selec].type != sphere && rt->object[rt->selec].type != \
		lights && rt->object[rt->selec].type != triangle && rt->rot_obj == 1)
		ft_rotate_obj(rt, (t_vec){{(float)rt->object[rt->selec].rot_x * M_PI
			/ 180.0, (float)rt->object[rt->selec].rot_y * M_PI / 180.0, 0}});
	else
		ft_rotate(rt, (t_vec){{(float)rt->camera.rot_x * M_PI / 180.0,
			(float)rt->camera.rot_y * M_PI / 180.0, 0}});
}

void	ft_moov_obj_obj(t_mini_rt *rt, float speed, t_vec move)
{
	if (move.z)
		rt->object[rt->selec].coord = ft_vec_add(rt->object[rt->selec].coord,
				(ft_vec_scale(rt->camera.forward, move.z * speed)));
	if (move.x)
		rt->object[rt->selec].coord = ft_vec_add(rt->object[rt->selec].coord,
				(ft_vec_scale(rt->camera.right, move.x * speed)));
	if (move.y)
		rt->object[rt->selec].coord = ft_vec_add(rt->object[rt->selec].coord,
				(ft_vec_scale((t_vec){{0, 1, 0, 0}}, move.y * speed)));
}

void	ft_moov_obj_cone(t_mini_rt *rt, float speed, t_vec move)
{
	if (move.z)
	{
		rt->object[rt->selec].coord = ft_vec_add(rt->object[rt->selec].coord,
				(ft_vec_scale(rt->camera.forward, move.z * speed)));
		rt->object[rt->selec].specificites.cone.apex = \
		ft_vec_add(rt->object[rt->selec].specificites.cone.apex,
				(ft_vec_scale(rt->camera.forward, move.z * speed)));
	}
	if (move.x)
	{
		rt->object[rt->selec].coord = ft_vec_add(rt->object[rt->selec].coord,
				(ft_vec_scale(rt->camera.right, move.x * speed)));
		rt->object[rt->selec].specificites.cone.apex = \
		ft_vec_add(rt->object[rt->selec].specificites.cone.apex,
				(ft_vec_scale(rt->camera.right, move.x * speed)));
	}
	if (move.y)
	{
		rt->object[rt->selec].coord = ft_vec_add(rt->object[rt->selec].coord,
				(ft_vec_scale((t_vec){{0, 1, 0, 0}}, move.y * speed)));
		rt->object[rt->selec].specificites.cone.apex = \
		ft_vec_add(rt->object[rt->selec].specificites.cone.apex,
				(ft_vec_scale((t_vec){{0, 1, 0, 0}}, move.y * speed)));
	}
}

void	ft_moov_obj_light(t_mini_rt *rt, float speed, t_vec move)
{
	int	index_light;

	index_light = rt->object[rt->selec].specificites.lights.index;
	if (move.z)
		rt->light[index_light].coord = ft_vec_add(rt->light[index_light].coord,
				(ft_vec_scale(rt->camera.forward, move.z * speed)));
	if (move.x)
		rt->light[index_light].coord = ft_vec_add(rt->light[index_light].coord,
				(ft_vec_scale(rt->camera.right, move.x * speed)));
	if (move.y)
		rt->light[index_light].coord = ft_vec_add(rt->light[index_light].coord,
				(ft_vec_scale((t_vec){{0, 1, 0, 0}}, move.y * speed)));
}
