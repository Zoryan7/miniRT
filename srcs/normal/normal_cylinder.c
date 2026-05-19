/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:53:42 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:04:14 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

t_vec	ft_normal_cylinder(t_object object, float t, t_ray ray)
{
	t_vec	hit_point;
	t_vec	co;
	t_vec	normal;
	float	m;

	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t));
	m = ft_vec_dot(ft_vec_sub(hit_point, object.coord), object.vec);
	if (m <= -(object.specificites.cylinder.height * 0.5f) + 0.001f
		|| m >= object.specificites.cylinder.height * 0.5f - 0.001f)
		return (ft_normal_plane(object, ray));
	co = ft_vec_sub(hit_point, object.coord);
	normal = ft_vec_normalize(ft_vec_sub(co, ft_vec_scale(object.vec, m)));
	if (ft_vec_dot(normal, ray.direction) > 0)
		return (ft_vec_scale(normal, -1));
	return (normal);
}
