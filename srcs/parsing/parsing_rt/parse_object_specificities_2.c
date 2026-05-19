/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_specificities_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:40:56 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 09:25:55 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_parse_r_box_specificities(char *line, t_object_info *object, int *i)
{
	object->object.type = rounded_box;
	if (ft_triple_recup_float_2(line, &object->object.vec, i))
		return (1);
	if (ft_check_normalize(object->object.vec))
		return (1);
	if (ft_triple_recup_float_2(line, &object->object.up_vec, i))
		return (1);
	if (ft_check_normalize(object->object.up_vec))
		return (1);
	object->object.vec.w = 1;
	object->object.up_vec.w = 1;
	object->object.init_vec = object->object.vec;
	object->object.init_up_vec = object->object.up_vec;
	object->object.specificites.rounded_box.init_coord = object->object.coord;
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_triple_recup_float_3(line,
			&object->object.specificites.rounded_box.size, i))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.rounded_box.radius, i,
			3) || !(object->object.specificites.rounded_box.radius > 0))
		return (1);
	return (0);
}

int	ft_parse_box_specificities(char *line, t_object_info *object, int *i)
{
	object->object.type = box;
	object->object.specificites.box.aabb.min = object->object.coord;
	if (ft_recup_float(line, &object->object.specificites.box.aabb.max.x, i, 0)
		|| !(object->object.specificites.box.aabb.max.x > 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.box.aabb.max.y, i, 1)
		|| !(object->object.specificites.box.aabb.max.y > 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.box.aabb.max.z, i, 2)
		|| !(object->object.specificites.box.aabb.max.z > 0))
		return (1);
	object->object.specificites.box.aabb.max.x += object->object.coord.x;
	object->object.specificites.box.aabb.max.y += object->object.coord.y;
	object->object.specificites.box.aabb.max.z += object->object.coord.z;
	return (0);
}
