/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:08:37 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 05:30:53 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	ft_valid_hit(t_mini_rt *rt, t_calcul_color info)
{
	return (info.dist_obj != INFINITY && info.ind_obj >= 0
		&& info.ind_obj < rt->size_object);
}

void	ft_color_normal(t_vec *final_color, t_ray ray)
{
	final_color->r = (ray.normal.r + 1.0f) / 2;
	final_color->g = (ray.normal.g + 1.0f) / 2;
	final_color->b = (ray.normal.b + 1.0f) / 2;
}

void	ft_color_opti(t_mini_rt *rt, t_calcul_color info, t_vec *final_color)
{
	if (rt->first_hit[info.task.y * rt->info.width + info.task.x] == -1)
	{
		final_color->r = 0;
		final_color->g = 255;
		final_color->b = 0;
	}
	else if (rt->first_hit[info.task.y * rt->info.width + info.task.x] == -2)
	{
		final_color->r = 255;
		final_color->g = 0;
		final_color->b = 0;
	}
	else
	{
		final_color->r = rt->first_hit[info.task.y * rt->info.width
			+ info.task.x] / (float)rt->size_object;
		final_color->g = rt->first_hit[info.task.y * rt->info.width
			+ info.task.x] / (float)rt->size_object;
		final_color->b = rt->first_hit[info.task.y * rt->info.width
			+ info.task.x] / (float)rt->size_object;
	}
}

void	ft_color_debug(t_mini_rt *rt, t_calcul_color info, t_vec *final_color,
		t_ray ray)
{
	if (rt->opti_on == 1 && rt->nb_img > 2)
		ft_color_opti(rt, info, final_color);
	else if (rt->normal_on)
		ft_color_normal(final_color, ray);
}

t_vec	ft_final_color(t_mini_rt *rt, t_ray ray, t_calcul_color info)
{
	t_info_final_color	i;

	i.obj_color = (t_vec){{0.0f, 0.0f, 0.0f, 0.0f}};
	if (!ft_valid_hit(rt, info))
		return (i.obj_color);
	if (rt->object[info.ind_obj].id_texture != -1)
		i.obj_color = ft_tex_color(rt, info.dist_obj, info.ind_obj, ray);
	else
		i.obj_color = rt->object[info.ind_obj].color;
	i.rand = ft_rand() * (float)rt->size_light;
	i.intensity = ft_light(rt, info, ray, i.rand);
	i.a_color.r = i.obj_color.r * rt->ambient.color.r * rt->ambient.brightness;
	i.a_color.g = i.obj_color.g * rt->ambient.color.g * rt->ambient.brightness;
	i.a_color.b = i.obj_color.b * rt->ambient.color.b * rt->ambient.brightness;
	i.diffuse_color.r = i.obj_color.r * rt->light[i.rand].color.r
		* rt->light[i.rand].brightness * i.intensity;
	i.diffuse_color.g = i.obj_color.g * rt->light[i.rand].color.g
		* rt->light[i.rand].brightness * i.intensity;
	i.diffuse_color.b = i.obj_color.b * rt->light[i.rand].color.b
		* rt->light[i.rand].brightness * i.intensity;
	i.final_color.r = i.a_color.r + i.diffuse_color.r;
	i.final_color.g = i.a_color.g + i.diffuse_color.g;
	i.final_color.b = i.a_color.b + i.diffuse_color.b;
	i.final_color.t = 0.0;
	ft_color_debug(rt, info, &i.final_color, ray);
	return (i.final_color);
}
