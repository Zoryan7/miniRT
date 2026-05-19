/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:46:49 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:36:46 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_moov_triangle_y(t_mini_rt *rt, float speed, t_vec move)
{
	if (move.y)
	{
		rt->object[rt->selec].specificites.triangle.a = \
		ft_vec_add(rt->object[rt->selec].specificites.triangle.a,
				(ft_vec_scale((t_vec){{0, 1, 0, 0}}, move.y * speed)));
		rt->object[rt->selec].specificites.triangle.b = \
		ft_vec_add(rt->object[rt->selec].specificites.triangle.b,
				(ft_vec_scale((t_vec){{0, 1, 0, 0}}, move.y * speed)));
		rt->object[rt->selec].specificites.triangle.c = \
		ft_vec_add(rt->object[rt->selec].specificites.triangle.c,
				(ft_vec_scale((t_vec){{0, 1, 0, 0}}, move.y * speed)));
	}
}

void	ft_moov_obj_triangle(t_mini_rt *rt, float speed, t_vec move)
{
	if (move.z)
	{
		rt->object[rt->selec].specificites.triangle.a = \
		ft_vec_add(rt->object[rt->selec].specificites.triangle.a,
				(ft_vec_scale(rt->camera.forward, move.z * speed)));
		rt->object[rt->selec].specificites.triangle.b = \
		ft_vec_add(rt->object[rt->selec].specificites.triangle.b,
				(ft_vec_scale(rt->camera.forward, move.z * speed)));
		rt->object[rt->selec].specificites.triangle.c = \
		ft_vec_add(rt->object[rt->selec].specificites.triangle.c,
				(ft_vec_scale(rt->camera.forward, move.z * speed)));
	}
	if (move.x)
	{
		rt->object[rt->selec].specificites.triangle.a = \
		ft_vec_add(rt->object[rt->selec].specificites.triangle.a,
				(ft_vec_scale(rt->camera.right, move.x * speed)));
		rt->object[rt->selec].specificites.triangle.b = \
		ft_vec_add(rt->object[rt->selec].specificites.triangle.b,
				(ft_vec_scale(rt->camera.right, move.x * speed)));
		rt->object[rt->selec].specificites.triangle.c = \
		ft_vec_add(rt->object[rt->selec].specificites.triangle.c,
				(ft_vec_scale(rt->camera.right, move.x * speed)));
	}
	ft_moov_triangle_y(rt, speed, move);
}
