/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:53:39 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 03:54:58 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

t_vec	ft_normal_cone(t_object object, float t, t_ray ray)
{
	t_vec	hit_point;
	t_vec	co;
	t_vec	normal;
	float	pente;
	float	m;

	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t));
	m = ft_vec_dot(ft_vec_sub(hit_point, object.coord), object.vec);
	if (ft_absf(m) <= 0.001f)
		return (ft_normal_plane(object, ray));
	co = ft_vec_sub(hit_point, object.specificites.cone.apex);
	pente = object.specificites.cone.radius / object.specificites.cone.height;
	pente *= pente;
	m = ft_vec_dot(co, object.vec);
	normal = ft_vec_normalize(ft_vec_sub(co, ft_vec_scale(object.vec, (1
						+ pente) * m)));
	if (ft_vec_dot(normal, ray.direction) > 0)
		normal = ft_vec_scale(normal, -1);
	return (normal);
}
