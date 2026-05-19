/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:05:59 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 05:17:11 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	ft_valid_hit(t_mini_rt *rt, t_calcul_color info)
{
	return (info.dist_obj != INFINITY && info.ind_obj >= 0
		&& info.ind_obj < rt->size_object);
}

void	ft_inter_choice(t_calcul_color *info, t_vec2 inter)
{
	if (inter.x < info->dist_obj && inter.y > 0)
	{
		if (inter.x > 0.001f)
		{
			info->out = 0;
			info->dist_obj = inter.x;
			info->ind_obj = info->i;
		}
		else if (inter.y > 0.001f)
		{
			info->out = 1;
			info->dist_obj = inter.y;
			info->ind_obj = info->i;
		}
	}
	info->i++;
}

t_vec	ft_choose_color(t_mini_rt *rt, t_ray ray, t_calcul_color info, int j)
{
	if (!ft_valid_hit(rt, info))
	{
		if (j == 0)
			return ((t_vec){{0, 0, 0, 0}});
		return (ft_ambient_color(rt, ray, info.task));
	}
	if (j == 0)
	{
		ray.normal = ft_choose_normal(rt->object[info.ind_obj],
				info.dist_obj, ray);
		return (ft_final_color(rt, ray, info));
	}
	return (ft_calcul_next_ray(rt, ray, info, j));
}

t_vec	ft_apply_bvh(int touch, t_vec color, t_mini_rt *rt)
{
	if (rt->bvh_on == 0)
		return (color);
	if (touch == 0)
		return (color);
	return ((t_vec){{(float)touch / 15, (float)touch / 15, (float)touch / 15}});
}

void	ft_init_info_calcul(t_calcul_color *info, t_task task)
{
	info->j_obj = -1;
	info->touch = 0;
	info->dist_obj = INFINITY;
	info->ind_obj = __INT_MAX__;
	info->out = 0;
	info->task = task;
}

t_vec	ft_calcul_color(t_mini_rt *rt, t_ray ray, int j, t_task task)
{
	t_vec2			inter;
	t_calcul_color	info;
	t_vec			color;

	ft_init_info_calcul(&info, task);
	if (ft_did_i_do_the_opti(rt, j, task))
		ft_do_opti(rt, task, &info, ray);
	else
	{
		info.i = 0;
		while (info.i < rt->size_object && rt->object[info.i].type == plane)
		{
			inter = ft_choose_intersect(rt->object[info.i], ray);
			ft_inter_choice(&info, inter);
		}
		inter = ft_intersect_bvh(ray, rt->bvh, rt, &info);
	}
	if (rt->nb_img == 3 && j == rt->info.bounce)
		ft_create_opti(rt, task, &info);
	j--;
	if (ft_valid_hit(rt, info) && rt->object[info.ind_obj].type == lights)
		color.v = rt->object[info.ind_obj].color.v;
	else
		color = ft_choose_color(rt, ray, info, j);
	return (ft_apply_bvh(info.touch, color, rt));
}
