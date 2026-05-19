/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:21:42 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:10:52 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_check_good_values_sphere(t_object_info *object)
{
	float	diameter;
	float	radius;

	diameter = object->object.specificites.sphere.diameter;
	radius = object->object.specificites.sphere.radius;
	if (object->object.specificites.sphere.diameter < 0
		&& object->object.specificites.sphere.radius < 0)
		return (ft_putstr_fd("no diameter in sphere", 2), 1);
	if (object->object.specificites.sphere.diameter < 0)
		object->object.specificites.sphere.diameter = radius * 2.0f;
	if (object->object.specificites.sphere.radius < 0)
		object->object.specificites.sphere.radius = diameter * 0.5f;
	return (0);
}

int	ft_check_good_values_plane(t_object_info *object)
{
	if (object->object.vec.w == 0)
		return (ft_putstr_fd("missing normal in plane", 2), 1);
	return (0);
}

int	ft_check_good_values_cylinder(t_object_info *object)
{
	float	diameter;
	float	radius;

	diameter = object->object.specificites.cylinder.diameter;
	radius = object->object.specificites.cylinder.radius;
	if (object->object.vec.w == 0)
		return (ft_putstr_fd("missing normal in cylinder", 2), 1);
	if (object->object.specificites.cylinder.height < 0)
		return (ft_putstr_fd("no height in cylinder", 2), 1);
	if (object->object.specificites.cylinder.diameter < 0
		&& object->object.specificites.cylinder.radius < 0)
		return (ft_putstr_fd("no diameter in cylinder", 2), 2);
	if (object->object.specificites.cylinder.diameter < 0)
		object->object.specificites.cylinder.diameter = radius * 2.0f;
	if (object->object.specificites.cylinder.radius < 0)
		object->object.specificites.cylinder.radius = diameter * 0.5f;
	return (0);
}

int	ft_check_good_values_cone(t_object_info *object)
{
	float	diameter;
	float	radius;

	diameter = object->object.specificites.cone.diameter;
	radius = object->object.specificites.cone.radius;
	if (object->object.vec.w == 0)
		return (ft_putstr_fd("missing normal in cone", 2), 1);
	if (object->object.specificites.cone.height < 0)
		return (ft_putstr_fd("no height in cone", 2), 1);
	if (object->object.specificites.cone.diameter < 0
		&& object->object.specificites.cone.radius < 0)
		return (ft_putstr_fd("no diameter in cone", 2), 1);
	if (object->object.specificites.cone.diameter < 0)
		object->object.specificites.cone.diameter = radius * 2.0f;
	if (object->object.specificites.cone.radius < 0)
		object->object.specificites.cone.radius = diameter * 0.5f;
	return (0);
}

int	ft_check_good_values_rounded_box(t_object_info *object)
{
	if (object->object.vec.w == 0)
		return (ft_putstr_fd("missing normal in rounded box", 2), 1);
	if (object->object.specificites.rounded_box.size.w < 0)
		return (ft_putstr_fd("no height in rounded box", 2), 1);
	if (object->object.specificites.rounded_box.radius < 0)
		return (ft_putstr_fd("no diameter in rounded box", 2), 1);
	return (0);
}
