/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:53:49 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 03:54:30 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

t_vec	ft_normal_sphere(t_object object, float t, t_ray ray)
{
	t_vec	hit_point;
	t_vec	normal;

	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t));
	normal = ft_vec_normalize(ft_vec_sub(hit_point, object.coord));
	if (ft_vec_dot(normal, ray.direction) > 0)
		return (ft_vec_scale(ft_vec_normalize(normal), -1));
	return (ft_vec_normalize(normal));
}
