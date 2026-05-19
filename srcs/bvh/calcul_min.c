/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:59:00 by ymoumene          #+#    #+#             */
/*   Updated: 2026/05/18 14:21:59 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

static t_vec	ft_min_cone(t_object object)
{
	t_vec	min;

	min.x = ft_minf(object.coord.x - object.specificites.cone.radius,
			object.specificites.cone.apex.x - object.specificites.cone.radius);
	min.y = ft_minf(object.coord.y - object.specificites.cone.radius,
			object.specificites.cone.apex.y - object.specificites.cone.radius);
	min.z = ft_minf(object.coord.z - object.specificites.cone.radius,
			object.specificites.cone.apex.z - object.specificites.cone.radius);
	return (min);
}

static t_vec	ft_min_cylinder(t_object object)
{
	t_vec	min;
	t_vec	bottom;

	bottom.v = object.coord.v - (object.vec.v
			* (object.specificites.cylinder.height * 0.5f));
	min.x = ft_minf(object.coord.x - object.specificites.cylinder.radius,
			bottom.x - object.specificites.cylinder.radius);
	min.y = ft_minf(object.coord.y - object.specificites.cylinder.radius,
			bottom.y - object.specificites.cylinder.radius);
	min.z = ft_minf(object.coord.z - object.specificites.cylinder.radius,
			bottom.z - object.specificites.cylinder.radius);
	return (min);
}

static t_vec	ft_min_triangle(t_object object)
{
	t_vec	min;

	min.x = ft_minf(object.specificites.triangle.a.x,
			ft_minf(object.specificites.triangle.b.x,
				object.specificites.triangle.c.x));
	min.y = ft_minf(object.specificites.triangle.a.y,
			ft_minf(object.specificites.triangle.b.y,
				object.specificites.triangle.c.y));
	min.z = ft_minf(object.specificites.triangle.a.z,
			ft_minf(object.specificites.triangle.b.z,
				object.specificites.triangle.c.z));
	return (min);
}

static t_vec	ft_calcul_min_rounded_box(t_object object)
{
	t_vec	min;
	float	size;

	size = ft_maxf(ft_maxf(object.specificites.rounded_box.size.width,
				object.specificites.rounded_box.size.height),
			object.specificites.rounded_box.size.depth);
	min.x = object.coord.x - (size * 0.5f)
		- object.specificites.rounded_box.radius * 2;
	min.y = object.coord.y - (size * 0.5f)
		- object.specificites.rounded_box.radius * 2;
	min.z = object.coord.z - (size * 0.5f)
		- object.specificites.rounded_box.radius * 2;
	return (min);
}

t_vec	ft_calcul_min(t_object object)
{
	t_vec	dest;

	if (object.type == sphere)
	{
		dest.v = object.coord.v - object.specificites.sphere.radius;
		return (dest);
	}
	else if (object.type == lights)
	{
		dest.v = object.coord.v - object.specificites.lights.radius;
		return (dest);
	}
	else if (object.type == cone)
		return (ft_min_cone(object));
	else if (object.type == rounded_box)
		return (ft_calcul_min_rounded_box(object));
	else if (object.type == box)
		return (object.coord);
	else if (object.type == cylinder)
		return (ft_min_cylinder(object));
	else if (object.type == triangle)
		return (ft_min_triangle(object));
	else
		return ((t_vec){{0.00f, 0.00f, 0.00f}});
}
