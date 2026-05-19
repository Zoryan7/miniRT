/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:53:01 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/11 13:39:48 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	ft_small_menu_1(t_mini_rt *rt)
{
	if (rt->selec == 22 - 1 + rt->size_object + 31 && rt->page != 2)
	{
		rt->page = 2;
		rt->nb_img = 0;
		rt->selec = __INT_MAX__;
	}
	else if (rt->selec == 24 - 1 + rt->size_object + 31)
	{
		ft_close(rt);
		rt->selec = __INT_MAX__;
	}
}

static void	ft_calcul_ray(t_mini_rt *rt, t_ray *ray, int x, int y)
{
	t_vec			target;

	target = rt->camera.view_origin;
	target.v = target.v + rt->camera.delta_u.v * (float)x;
	target.v = target.v + rt->camera.delta_v.v * (float)y;
	ray->origin = rt->camera.coord;
	ray->direction = ft_vec_normalize(ft_vec_sub(target, ray->origin));
	ray->r_direction = ft_vec_divide_vec((t_vec){{1.0f, 1.0f, 1.0f}},
			ray->direction);
}

void	ft_select_control(t_mini_rt *rt, int x, int y)
{
	t_vec2			inter;
	t_ray			ray;
	t_select_info	info;

	info.i = rt->size_object + 31;
	info.dist_obj = INFINITY;
	info.ind_obj = __INT_MAX__;
	ft_calcul_ray(rt, &ray, x, y);
	while (info.i < 25 + rt->size_object + 30)
	{
		if (info.i == rt->size_object + 51 || info.i == rt->size_object + 55)
		{
			info.i++;
			continue ;
		}
		inter = ft_intersect_r_box(ray, rt->object[info.i]);
		if (inter.x < info.dist_obj && inter.y > 0)
		{
			info.dist_obj = inter.x;
			info.ind_obj = info.i;
		}
		info.i++;
	}
	rt->selec = info.ind_obj;
	ft_small_menu_1(rt);
}
