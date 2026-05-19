/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_object_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:11:09 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:11:57 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

void	ft_new_object_sphere(t_object_info *dest)
{
	dest->object.type = sphere;
	dest->object.specificites.sphere.diameter = -1;
}

void	ft_new_object_rounded_box(t_object_info *dest)
{
	dest->object.type = rounded_box;
	dest->object.specificites.rounded_box.size = (t_vec){{0, 0, 0, 0}};
	dest->object.specificites.rounded_box.radius = -1;
}

void	ft_new_object_box(t_object_info *dest)
{
	dest->object.type = box;
	dest->object.specificites.box.aabb.min.w = -1;
	dest->object.specificites.box.aabb.max.y = -1;
	dest->object.specificites.box.aabb.max.x = -1;
	dest->object.specificites.box.aabb.max.z = -1;
}
