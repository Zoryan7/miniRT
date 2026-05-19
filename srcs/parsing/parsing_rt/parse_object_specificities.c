/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_specificities.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:21:19 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 04:37:37 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_parse_sphere_specificities(char *line, t_object_info *object, int *i)
{
	object->object.type = sphere;
	if (ft_recup_float(line, &object->object.specificites.sphere.diameter, i,
			2))
		return (1);
	object->object.specificites.sphere.radius = ft_radius(object);
	return (0);
}

int	ft_parse_cylinder_specificities(char *line, t_object_info *object, int *i)
{
	object->object.type = cylinder;
	if ((ft_recup_float(line, &object->object.vec.x, i, 0)
			|| !(object->object.vec.x >= -1 && object->object.vec.x <= 1))
		|| (ft_recup_float(line, &object->object.vec.y, i, 1)
			|| !(object->object.vec.y >= -1 && object->object.vec.y <= 1))
		|| (ft_recup_float(line, &object->object.vec.z, i, 2)
			|| !(object->object.vec.z >= -1 && object->object.vec.z <= 1)))
		return (1);
	if (ft_check_normalize(object->object.vec))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.cylinder.diameter, i,
			2) || object->object.specificites.cylinder.diameter <= 0)
		return (1);
	object->object.specificites.cylinder.radius = ft_radius(object);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.cylinder.height, i, 2)
		|| object->object.specificites.cylinder.height <= 0)
		return (1);
	object->object.init_vec = object->object.vec;
	return (0);
}

int	ft_parse_cone_specificities(char *line, t_object_info *object, int *i)
{
	object->object.type = cone;
	if ((ft_recup_float(line, &object->object.vec.x, i, 0)
			|| !(object->object.vec.x >= -1 && object->object.vec.x <= 1))
		|| (ft_recup_float(line, &object->object.vec.y, i, 1)
			|| !(object->object.vec.y >= -1 && object->object.vec.y <= 1))
		|| (ft_recup_float(line, &object->object.vec.z, i, 2)
			|| !(object->object.vec.z >= -1 && object->object.vec.z <= 1)))
		return (1);
	if (ft_check_normalize(object->object.vec) || ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.cone.diameter, i, 2)
		|| object->object.specificites.cone.diameter <= 0)
		return (1);
	object->object.specificites.cone.radius = ft_radius(object);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.cone.height, i, 2)
		|| object->object.specificites.cone.height <= 0)
		return (1);
	object->object.specificites.cone.apex = ft_vec_add(object->object.coord,
			ft_vec_scale(object->object.vec,
				object->object.specificites.cone.height));
	object->object.init_vec = object->object.vec;
	return (0);
}

int	ft_parse_plane_specificities(char *line, t_object_info *object, int *i)
{
	object->object.type = plane;
	if (ft_recup_float(line, &object->object.vec.x, i, 0)
		|| !(object->object.vec.x >= -1 && object->object.vec.x <= 1))
		return (1);
	if (ft_recup_float(line, &object->object.vec.y, i, 1)
		|| !(object->object.vec.y >= -1 && object->object.vec.y <= 1))
		return (1);
	if (ft_recup_float(line, &object->object.vec.z, i, 2)
		|| !(object->object.vec.z >= -1 && object->object.vec.z <= 1))
		return (1);
	if (ft_check_normalize(object->object.vec))
		return (1);
	object->object.init_vec = object->object.vec;
	return (0);
}
