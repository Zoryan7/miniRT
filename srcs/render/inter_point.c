/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:04 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:36:47 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static float	ft_point_in_box(t_object obj, t_vec point)
{
	t_aabb	box;
	t_vec	center;

	box = obj.specificites.box.aabb;
	if (point.x <= box.min.x + POINT_IN_EPS || point.x >= box.max.x
		- POINT_IN_EPS || point.y <= box.min.y + POINT_IN_EPS
		|| point.y >= box.max.y - POINT_IN_EPS || point.z <= box.min.z
		+ POINT_IN_EPS || point.z >= box.max.z - POINT_IN_EPS)
		return (INFINITY);
	center = ft_vec_scale(ft_vec_add(box.min, box.max), 0.5f);
	return (ft_point_metric(point, center));
}

static float	ft_point_in_cylinder(t_object obj, t_vec point)
{
	t_vec	axis;
	t_vec	diff;
	float	proj;
	float	radial2;
	float	half_h;

	axis = ft_vec_normalize(obj.vec);
	diff = ft_vec_sub(point, obj.coord);
	proj = ft_vec_dot(diff, axis);
	half_h = obj.specificites.cylinder.height * 0.5f;
	if (proj <= -half_h + POINT_IN_EPS || proj >= half_h - POINT_IN_EPS)
		return (INFINITY);
	radial2 = ft_vec_dot(diff, diff) - proj * proj;
	if (radial2 >= (obj.specificites.cylinder.radius - POINT_IN_EPS)
		* (obj.specificites.cylinder.radius - POINT_IN_EPS))
		return (INFINITY);
	return (ft_point_metric(point, obj.coord));
}

static float	ft_point_in_cone(t_object obj, t_vec point)
{
	t_info_cone_point	info;

	info.axis = ft_vec_normalize(obj.vec);
	info.diff = ft_vec_sub(point, obj.specificites.cone.apex);
	info.proj = ft_vec_dot(info.diff, info.axis);
	info.height = obj.specificites.cone.height;
	if (info.proj >= -POINT_IN_EPS || info.proj <= -info.height + POINT_IN_EPS)
		return (INFINITY);
	info.limit_r = obj.specificites.cone.radius * (-info.proj / info.height)
		- POINT_IN_EPS;
	if (info.limit_r <= 0.0f)
		return (INFINITY);
	info.radial2 = ft_vec_dot(info.diff, info.diff) - info.proj * info.proj;
	if (info.radial2 >= info.limit_r * info.limit_r)
		return (INFINITY);
	info.mid = ft_vec_add(obj.coord, ft_vec_scale(info.axis, info.height
				* 0.5f));
	return (ft_point_metric(point, info.mid));
}

static float	ft_point_in_rbox(t_object obj, t_vec point)
{
	t_rbox_basis	basis;
	t_vec			local;
	t_vec			center;
	t_vec			half_size;

	ft_rbox_basis_i(&basis, obj.vec, obj.up_vec);
	local = ft_to_rbox_local_i(ft_vec_sub(point, obj.coord), basis);
	half_size = ft_vec_divide(obj.specificites.rounded_box.size, 2);
	if (ft_rbox_sdf(local, half_size, obj.specificites.rounded_box.radius)
		>= -POINT_IN_EPS)
		return (INFINITY);
	center = obj.coord;
	return (ft_point_metric(point, center));
}

float	ft_choose_point(t_object obj, t_vec point)
{
	if (obj.type == sphere || obj.type == lights)
		return (ft_point_in_sphere(obj, point));
	if (obj.type == box)
		return (ft_point_in_box(obj, point));
	if (obj.type == cylinder)
		return (ft_point_in_cylinder(obj, point));
	if (obj.type == cone)
		return (ft_point_in_cone(obj, point));
	if (obj.type == rounded_box)
		return (ft_point_in_rbox(obj, point));
	return (INFINITY);
}
