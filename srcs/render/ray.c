/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:04:11 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 05:39:18 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_vec	ft_rdm_vec(float power)
{
	float	rdm_x;
	float	rdm_y;
	float	rdm_z;

	rdm_x = ft_rand() * power;
	rdm_y = ft_rand() * power;
	rdm_z = ft_rand() * power;
	return ((t_vec){{rdm_x, rdm_y, rdm_z, 0}});
}

t_ray	ft_init_ray(void)
{
	t_ray	ray;

	ray = (t_ray){
		.origin = (t_vec){{0.0f, 0.0f, 0.0f, 0.0f}},
		.destination = (t_vec){{0.0f, 0.0f, 0.0f, 0.0f}},
		.direction = (t_vec){{0.0f, 0.0f, 0.0f, 0.0f}},
		.r_direction = (t_vec){{0.0f, 0.0f, 0.0f, 0.0f}},
		.normal = (t_vec){{0.0f, 0.0f, 0.0f, 0.0f}},
		.eta = 0.0f,
	};
	return (ray);
}

t_vec	ft_calcul_next_ray(t_mini_rt *rt, t_ray old_ray, t_calcul_color info,
		int j)
{
	float (rdm) = 0.0f;
	t_ray (new_ray) = ft_init_ray();
	old_ray.normal = ft_choose_normal(rt->object[info.ind_obj], info.dist_obj,
			old_ray);
	if (rt->object[info.ind_obj].id_bump != -1)
		old_ray.normal = ft_bump_normal(rt, old_ray, info);
	if (rt->object[info.ind_obj].randomless > 0)
		old_ray.normal = ft_vec_normalize(ft_vec_add(old_ray.normal,
					ft_rdm_vec(rt->object[info.ind_obj].randomless)));
	new_ray.origin = ft_vec_add(old_ray.origin, ft_vec_scale(old_ray.direction,
				info.dist_obj));
	new_ray.destination = (t_vec){{0, 0, 0, 0}};
	if (rt->object[info.ind_obj].transparency > 0)
	{
		rdm = ft_rand();
		if (rdm <= rt->object[info.ind_obj].transparency)
		{
			ft_calcul_refracted_ray(rt, old_ray, &new_ray, info);
			return (ft_vec_mult(rt->object[info.ind_obj].color,
					ft_calcul_color(rt, new_ray, j, info.task)));
		}
	}
	ft_calcul_reflected_ray(old_ray, &new_ray);
	return (ft_gradient(ft_final_color(rt, old_ray, info), ft_calcul_color(rt,
				new_ray, j, info.task), rt->object[info.ind_obj].reflection));
}

void	ft_calcul_reflected_ray(t_ray old_ray, t_ray *new_ray)
{
	new_ray->eta = old_ray.eta;
	new_ray->direction = ft_vec_normalize(ft_vec_sub(old_ray.direction,
				ft_vec_scale(old_ray.normal, ft_vec_dot(old_ray.direction,
						old_ray.normal) * 2.0)));
	new_ray->r_direction = ft_vec_divide_vec((t_vec){{1.0f, 1.0f, 1.0f}},
			new_ray->direction);
}

void	ft_calcul_refracted_ray(t_mini_rt *rt, t_ray old_ray, t_ray *new_ray,
		t_calcul_color info)
{
	float	eta_all;
	float	angle;
	t_vec	parallel;
	t_vec	perpendicular;

	if (info.out == 1)
		new_ray->eta = ft_determine_eta(rt, new_ray->origin);
	else
		new_ray->eta = rt->object[info.ind_obj].refraction_indice;
	if (new_ray->eta == old_ray.eta)
		new_ray->direction = old_ray.direction;
	eta_all = old_ray.eta / new_ray->eta;
	angle = -ft_vec_dot(old_ray.direction, old_ray.normal);
	perpendicular = ft_vec_scale(ft_vec_add(old_ray.direction,
				ft_vec_scale(old_ray.normal, angle)), eta_all);
	parallel = ft_vec_scale(old_ray.normal, -sqrt(ft_absf(1.0f
					- (ft_vec_length(perpendicular)
						* ft_vec_length(perpendicular)))));
	new_ray->direction = ft_vec_add(parallel, perpendicular);
	new_ray->r_direction = ft_vec_divide_vec((t_vec){{1.0f, 1.0f, 1.0f}},
			new_ray->direction);
}
