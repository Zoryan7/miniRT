/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:59:11 by ymoumene          #+#    #+#             */
/*   Updated: 2026/05/18 14:22:05 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

static t_vec	ft_max_cone(t_object object)
{
	t_vec	max;

	max.x = ft_maxf(object.coord.x + object.specificites.cone.radius,
			object.specificites.cone.apex.x + object.specificites.cone.radius);
	max.y = ft_maxf(object.coord.y + object.specificites.cone.radius,
			object.specificites.cone.apex.y + object.specificites.cone.radius);
	max.z = ft_maxf(object.coord.z + object.specificites.cone.radius,
			object.specificites.cone.apex.z + object.specificites.cone.radius);
	return (max);
}

static t_vec	ft_max_cylinder(t_object object)
{
	t_vec	max;
	t_vec	top;

	top.v = object.coord.v + (object.vec.v
			* (object.specificites.cylinder.height * 0.5f));
	max.x = ft_maxf(object.coord.x + object.specificites.cylinder.radius, top.x
			+ object.specificites.cylinder.radius);
	max.y = ft_maxf(object.coord.y + object.specificites.cylinder.radius, top.y
			+ object.specificites.cylinder.radius);
	max.z = ft_maxf(object.coord.z + object.specificites.cylinder.radius, top.z
			+ object.specificites.cylinder.radius);
	return (max);
}

static t_vec	ft_max_triangle(t_object object)
{
	t_vec	max;

	max.x = ft_maxf(object.specificites.triangle.a.x,
			ft_maxf(object.specificites.triangle.b.x,
				object.specificites.triangle.c.x));
	max.y = ft_maxf(object.specificites.triangle.a.y,
			ft_maxf(object.specificites.triangle.b.y,
				object.specificites.triangle.c.y));
	max.z = ft_maxf(object.specificites.triangle.a.z,
			ft_maxf(object.specificites.triangle.b.z,
				object.specificites.triangle.c.z));
	return (max);
}

static t_vec	ft_calcul_max_rounded_box(t_object object)
{
	t_vec	max;
	float	size;

	size = ft_maxf(ft_maxf(object.specificites.rounded_box.size.width,
				object.specificites.rounded_box.size.height),
			object.specificites.rounded_box.size.depth);
	max.x = object.coord.x + (size * 0.5f)
		+ object.specificites.rounded_box.radius * 2;
	max.y = object.coord.y + (size * 0.5f)
		+ object.specificites.rounded_box.radius * 2;
	max.z = object.coord.z + (size * 0.5f)
		+ object.specificites.rounded_box.radius * 2;
	return (max);
}

t_vec	ft_calcul_max(t_object object)
{
	t_vec	dest;

	if (object.type == sphere)
	{
		dest.v = object.coord.v + object.specificites.sphere.radius;
		return (dest);
	}
	else if (object.type == lights)
	{
		dest.v = object.coord.v + object.specificites.lights.radius;
		return (dest);
	}
	else if (object.type == cone)
		return (ft_max_cone(object));
	else if (object.type == rounded_box)
		return (ft_calcul_max_rounded_box(object));
	else if (object.type == box)
		return (object.specificites.box.aabb.max);
	else if (object.type == cylinder)
		return (ft_max_cylinder(object));
	else if (object.type == triangle)
		return (ft_max_triangle(object));
	else
		return ((t_vec){{0.00f, 0.00f, 0.00f}});
}
