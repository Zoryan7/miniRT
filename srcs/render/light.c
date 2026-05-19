/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:52:31 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 05:43:59 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	ft_valid_hit(t_mini_rt *rt, t_calcul_color info)
{
	return (info.dist_obj != INFINITY && info.ind_obj >= 0
		&& info.ind_obj < rt->size_object);
}

t_vec	ft_rdm_point(t_light light)
{
	float	rdm_x;
	float	rdm_y;
	float	rdm_z;

	rdm_x = light.radius + 1;
	rdm_y = light.radius + 1;
	rdm_z = light.radius + 1;
	while (rdm_x > light.radius)
		rdm_x = ft_rand() * light.radius;
	while (rdm_y > light.radius)
		rdm_y = ft_rand() * light.radius;
	while (rdm_z > light.radius)
		rdm_z = ft_rand() * light.radius;
	return ((t_vec){{rdm_x * 2.0f - light.radius, rdm_y * 2.0f - light.radius,
			rdm_z * 2.0f - light.radius, 0}});
}

t_ray	ft_create_shadow(t_mini_rt *rt, t_vec hit_point, int rand,
		t_vec point_light)
{
	t_ray	shadow;

	shadow.origin = hit_point;
	if (rt->light[rand].radius == 0)
		shadow.direction = ft_vec_normalize(ft_vec_sub(rt->light[rand].coord,
					hit_point));
	else
		shadow.direction = ft_vec_normalize(ft_vec_sub(point_light, hit_point));
	shadow.r_direction = ft_vec_divide_vec((t_vec){{1.0f, 1.0f, 1.0f}},
			shadow.direction);
	return (shadow);
}

t_info_light	ft_init_light_info(t_mini_rt *rt, t_calcul_color inf, t_ray ray,
		int rand)
{
	t_info_light	il;
	t_vec			hit_point;

	il.info.dist_obj = INFINITY;
	il.info.i = 0;
	il.info.ind_obj = __INT_MAX__;
	il.info.out = 0;
	il.info.touch = 0;
	il.info.j_obj = -1;
	il.point_light = ft_vec_add(rt->light[rand].coord,
			ft_rdm_point(rt->light[rand]));
	il.hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction,
				inf.dist_obj));
	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction,
				inf.dist_obj));
	il.shadow = ft_create_shadow(rt, hit_point, rand, il.point_light);
	il.dist_light = ft_vec_length(ft_vec_sub(il.hit_point, il.point_light))
		- rt->light[rand].radius;
	il.attenuation = 1.0f / (il.dist_light * il.dist_light + 1.0f);
	il.l = ft_vec_dot(ray.normal, il.shadow.direction);
	return (il);
}

float	ft_light(t_mini_rt *rt, t_calcul_color inf, t_ray ray, int rand)
{
	t_info_light	il;

	il = ft_init_light_info(rt, inf, ray, rand);
	while (il.info.i < rt->size_object && rt->object[il.info.i].type == plane)
	{
		if (il.info.i != inf.ind_obj)
		{
			il.inter = ft_choose_intersect(rt->object[il.info.i], il.shadow);
			ft_inter_choice(&il.info, il.inter);
		}
		else
			il.info.i++;
	}
	il.info.j_obj = inf.ind_obj;
	if (il.info.i < rt->size_object && il.info.dist_obj == INFINITY
		&& rt->object[il.info.i].type != lights)
		ft_intersect_bvh_light(il.shadow, rt->bvh, rt, &il.info);
	if (ft_valid_hit(rt, il.info)
		&& rt->object[il.info.ind_obj].type != lights)
		return (0);
	if (il.l <= 0.00)
		return (0);
	return (il.l * (rt->size_light + 1) * 200 * il.attenuation);
}
