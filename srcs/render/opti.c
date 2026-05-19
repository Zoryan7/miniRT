/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 05:06:07 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 05:07:59 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	ft_valid_first_hit(t_mini_rt *rt, int hit)
{
	return (hit >= 0 && hit < rt->size_object);
}

void	ft_create_opti(t_mini_rt *rt, t_task task, t_calcul_color *info)
{
	if (!ft_valid_first_hit(rt, info->ind_obj))
		rt->first_hit[task.y * rt->info.width + task.x] = -2;
	else
		rt->first_hit[task.y * rt->info.width + task.x] = info->ind_obj;
	if (info->dist_obj == INFINITY && ft_check_corner_pix_sky(rt, task))
		rt->first_hit[task.y * rt->info.width + task.x] = -1;
	else if (info->dist_obj == INFINITY || !ft_check_corner_pix_obj(rt, *info,
			task))
		rt->first_hit[task.y * rt->info.width + task.x] = -2;
}

void	ft_do_opti(t_mini_rt *rt, t_task task, t_calcul_color *info, t_ray ray)
{
	t_vec2	inter;
	int		hit;

	hit = rt->first_hit[task.y * rt->info.width + task.x];
	info->i = hit;
	if (ft_valid_first_hit(rt, hit))
	{
		inter = ft_choose_intersect(rt->object[hit], ray);
		ft_inter_choice(info, inter);
	}
}

int	ft_did_i_do_the_opti(t_mini_rt *rt, int j, t_task task)
{
	int	hit;

	hit = rt->first_hit[task.y * rt->info.width + task.x];
	return (rt->opti_on == 0 && rt->bvh_on == 0 && rt->nb_img > 3
		&& j == rt->info.bounce && (hit == -1 || ft_valid_first_hit(rt, hit)));
}
