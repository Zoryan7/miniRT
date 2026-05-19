/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 07:00:00 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 09:06:18 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

static t_vec2	ft_triangle_barycentric(t_object object, t_vec hit_point)
{
	t_triangle_info	info;

	info.p = ft_vec_sub(hit_point, object.specificites.triangle.a);
	info.dot00 = ft_vec_dot(object.specificites.triangle.ab,
			object.specificites.triangle.ab);
	info.dot01 = ft_vec_dot(object.specificites.triangle.ab,
			object.specificites.triangle.ac);
	info.dot11 = ft_vec_dot(object.specificites.triangle.ac,
			object.specificites.triangle.ac);
	info.dot20 = ft_vec_dot(info.p, object.specificites.triangle.ab);
	info.dot21 = ft_vec_dot(info.p, object.specificites.triangle.ac);
	info.inv_denom = 1.0f / (info.dot00 * info.dot11 - info.dot01 * info.dot01);
	info.uv.x = (info.dot11 * info.dot20 - info.dot01 * info.dot21)
		* info.inv_denom;
	info.uv.y = (info.dot00 * info.dot21 - info.dot01 * info.dot20)
		* info.inv_denom;
	return (info.uv);
}

t_vec	ft_normal_triangle(t_object object, float t, t_ray ray)
{
	t_vec2	bary;
	t_vec	normal;
	t_vec	hit_point;

	if (!object.specificites.triangle.has_vertex_normal)
		return (ft_normal_plane(object, ray));
	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t));
	bary = ft_triangle_barycentric(object, hit_point);
	normal.v = object.specificites.triangle.a_normal.v * (1.0f - bary.x
			- bary.y) + object.specificites.triangle.b_normal.v * bary.x
		+ object.specificites.triangle.c_normal.v * bary.y;
	if (ft_vec_dot(normal, ray.direction) > 0)
		normal = ft_vec_scale(normal, -1.0f);
	return (ft_vec_normalize(normal));
}
