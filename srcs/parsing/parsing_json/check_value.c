/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:29:17 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:24:52 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_check_good_values_box(t_aabb aabb)
{
	if (aabb.max.height < 0)
		return (ft_putstr_fd("no height in box", 2), 1);
	if (aabb.max.x < 0)
		return (ft_putstr_fd("no width in box", 2), 1);
	if (aabb.max.z < 0)
		return (ft_putstr_fd("no depth in box", 2), 1);
	if (aabb.max.x <= aabb.min.x)
		return (ft_putstr_fd("invalid width in box", 2), 1);
	if (aabb.max.y <= aabb.min.y)
		return (ft_putstr_fd("invalid height in box", 2), 1);
	if (aabb.max.z <= aabb.min.z)
		return (ft_putstr_fd("invalid depth in box", 2), 1);
	return (0);
}

int	ft_check_good_values_triangle(t_object_info *object)
{
	t_vec	temp;

	if (object->object.specificites.triangle.b.w == 0)
		return (ft_putstr_fd("missing point B in triangle", 2), 1);
	if (object->object.specificites.triangle.c.w == 0)
		return (ft_putstr_fd("missing point C in triangle", 2), 1);
	temp = object->object.specificites.triangle.c;
	object->object.specificites.triangle.ac.v = temp.v
		- object->object.specificites.triangle.a.v;
	temp = object->object.specificites.triangle.b;
	object->object.specificites.triangle.ab.v = temp.v
		- object->object.specificites.triangle.a.v;
	temp = ft_vec_cross(object->object.specificites.triangle.ab,
			object->object.specificites.triangle.ac);
	object->object.vec = ft_vec_normalize(temp);
	return (0);
}

int	ft_check_values_types(t_object_info *object)
{
	if (object->object.type == sphere)
		return (ft_check_good_values_sphere(object));
	if (object->object.type == plane)
		return (ft_check_good_values_plane(object));
	if (object->object.type == cylinder)
		return (ft_check_good_values_cylinder(object));
	if (object->object.type == cone)
		return (ft_check_good_values_cone(object));
	if (object->object.type == rounded_box)
		return (ft_check_good_values_rounded_box(object));
	if (object->object.type == box)
		return (ft_check_good_values_box(object->object.specificites.box.aabb));
	if (object->object.type == triangle)
		return (ft_check_good_values_triangle(object));
	return (0);
}

int	ft_check_good_values_object(t_object_info *object)
{
	object->object.init_vec = object->object.vec;
	object->object.init_up_vec = object->object.up_vec;
	if (object->object.coord.w == 0)
		return (ft_putstr_fd("missing coordinates in object", 2), 1);
	if (object->object.color.t == 0)
		return (ft_putstr_fd("missing color in object", 2), 1);
	if (ft_check_values_types(object))
		return (1);
	if (object->object.reflection == -1)
		object->object.reflection = 0;
	if (object->object.transparency == -1)
		object->object.transparency = 0;
	if (object->object.refraction_indice == -1)
		object->object.refraction_indice = 1;
	if (object->object.randomless == -1)
		object->object.randomless = 0;
	return (0);
}
