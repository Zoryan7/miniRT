/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:49:51 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 08:39:33 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"

static void	ft_uv_unwrap_component(float *a, float *b, float *c)
{
	if (((*a < 0.1f && *b > 0.9f) || (*b < 0.1f && *a > 0.9f))
		&& ft_absf(*a - *b) > 0.5f)
	{
		if (*a < *b)
			*a += 1.0f;
		else
			*b += 1.0f;
	}
	if (((*a < 0.1f && *c > 0.9f) || (*c < 0.1f && *a > 0.9f))
		&& ft_absf(*a - *c) > 0.5f)
	{
		if (*a < *c)
			*a += 1.0f;
		else
			*c += 1.0f;
	}
	if (((*b < 0.1f && *c > 0.9f) || (*c < 0.1f && *b > 0.9f))
		&& ft_absf(*b - *c) > 0.5f)
	{
		if (*b < *c)
			*b += 1.0f;
		else
			*c += 1.0f;
	}
}

static t_vec2	ft_uv_triangle_interp(t_object object, t_vec2 bary)
{
	float	u[3];
	float	v[3];
	t_vec2	uv;

	u[0] = object.specificites.triangle.a_uv.x;
	u[1] = object.specificites.triangle.b_uv.x;
	u[2] = object.specificites.triangle.c_uv.x;
	v[0] = object.specificites.triangle.a_uv.y;
	v[1] = object.specificites.triangle.b_uv.y;
	v[2] = object.specificites.triangle.c_uv.y;
	ft_uv_unwrap_component(&u[0], &u[1], &u[2]);
	ft_uv_unwrap_component(&v[0], &v[1], &v[2]);
	uv.x = u[0] * (1.0f - bary.x - bary.y) + u[1] * bary.x + u[2] * bary.y;
	uv.y = v[0] * (1.0f - bary.x - bary.y) + v[1] * bary.x + v[2] * bary.y;
	return (ft_uv_wrap(uv));
}

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

t_vec2	ft_uv_triangle(t_object object, t_vec hit_point)
{
	t_vec2	bary;

	bary = ft_triangle_barycentric(object, hit_point);
	if (!object.specificites.triangle.has_vertex_uv)
		return (ft_uv_wrap(bary));
	return (ft_uv_triangle_interp(object, bary));
}
