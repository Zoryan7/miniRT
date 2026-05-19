/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_point_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:15:36 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:36:48 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float	ft_point_metric(t_vec point, t_vec ref)
{
	t_vec	diff;

	diff = ft_vec_sub(point, ref);
	return (ft_vec_dot(diff, diff));
}

float	ft_point_in_sphere(t_object obj, t_vec point)
{
	t_vec	diff;
	float	dist;
	float	radius;

	radius = obj.specificites.sphere.radius - POINT_IN_EPS;
	if (radius <= 0.0f)
		return (INFINITY);
	diff = ft_vec_sub(point, obj.coord);
	dist = ft_vec_dot(diff, diff);
	if (dist < radius * radius)
		return (dist);
	return (INFINITY);
}
