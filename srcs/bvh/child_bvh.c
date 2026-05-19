/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bvh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:24:33 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 04:41:01 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

float	ft_choose_center_x(t_object *object)
{
	if (object->type == sphere || object->type == lights
		|| object->type == rounded_box)
		return (object->coord.x);
	else if (object->type == box)
		return (object->coord.x + ((object->specificites.box.aabb.max.x
					- object->coord.x) * 0.5f));
	else if (object->type == cone)
		return (object->coord.x + ((object->specificites.cone.apex.x
					- object->coord.x) * 0.5f));
	else if (object->type == cylinder)
		return (object->coord.x + ((object->specificites.cylinder.height * 0.5f)
				* object->vec.x));
	else if (object->type == triangle)
		return ((object->specificites.triangle.a.x
				+ object->specificites.triangle.b.x
				+ object->specificites.triangle.c.x) * 0.333f);
	return (0);
}

float	ft_choose_center_y(t_object *object)
{
	if (object->type == sphere || object->type == lights
		|| object->type == rounded_box)
		return (object->coord.y);
	else if (object->type == box)
		return (object->coord.y + ((object->specificites.box.aabb.max.y
					- object->coord.y) * 0.5f));
	else if (object->type == cone)
		return (object->coord.y + ((object->specificites.cone.apex.y
					- object->coord.y) * 0.5f));
	else if (object->type == cylinder)
		return (object->coord.y + ((object->specificites.cylinder.height * 0.5f)
				* object->vec.y));
	else if (object->type == triangle)
		return ((object->specificites.triangle.a.y
				+ object->specificites.triangle.b.y
				+ object->specificites.triangle.c.y) * 0.333f);
	return (0);
}

float	ft_choose_center(t_object *object, char axis)
{
	if (axis == 'x')
		return (ft_choose_center_x(object));
	else if (axis == 'y')
		return (ft_choose_center_y(object));
	else
	{
		if (object->type == sphere || object->type == lights
			|| object->type == rounded_box)
			return (object->coord.z);
		else if (object->type == box)
			return (object->coord.z + ((object->specificites.box.aabb.max.z
						- object->coord.z) * 0.5f));
		else if (object->type == cone)
			return (object->coord.z + ((object->specificites.cone.apex.z
						- object->coord.z) * 0.5f));
		else if (object->type == cylinder)
			return (object->coord.z + ((object->specificites.cylinder.height
						* 0.5f) * object->vec.z));
		else if (object->type == triangle)
			return ((object->specificites.triangle.a.z
					+ object->specificites.triangle.b.z
					+ object->specificites.triangle.c.z) * 0.333f);
	}
	return (0);
}

float	ft_choose_longest_axis(t_aabb dest, char *axis)
{
	float	len_x;
	float	len_y;
	float	len_z;

	len_x = dest.max.x - dest.min.x;
	len_y = dest.max.y - dest.min.y;
	len_z = dest.max.z - dest.min.z;
	if (len_x >= len_y && len_x >= len_z)
	{
		*axis = 'x';
		return ((dest.min.x + dest.max.x) * 0.5);
	}
	else if (len_y >= len_x && len_y >= len_z)
	{
		*axis = 'y';
		return ((dest.min.y + dest.max.y) * 0.5);
	}
	else
	{
		*axis = 'z';
		return ((dest.min.z + dest.max.z) * 0.5);
	}
	return (0);
}

int	ft_which_side_bvh(int i, t_bvh *parent, t_mini_rt *rt)
{
	float	center_object;
	float	center;
	char	axis;

	center = ft_choose_longest_axis(parent->aabb, &axis);
	center_object = ft_choose_center(&rt->object[parent->index_object[i]],
			axis);
	if (center_object < center)
		return (1);
	return (0);
}
