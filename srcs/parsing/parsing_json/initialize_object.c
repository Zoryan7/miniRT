/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:35:12 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 08:40:48 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

void	ft_new_object_cone(t_object_info *dest)
{
	dest->object.type = cone;
	dest->object.specificites.cone.height = -1;
	dest->object.specificites.cone.diameter = -1;
}

void	ft_new_object_triangle(t_object_info *dest)
{
	dest->object.type = triangle;
	dest->object.specificites.triangle.a = (t_vec){{0, 0, 0, 0}};
	dest->object.specificites.triangle.b = (t_vec){{0, 0, 0, 0}};
	dest->object.specificites.triangle.c = (t_vec){{0, 0, 0, 0}};
	dest->object.specificites.triangle.ac = (t_vec){{0, 0, 0, 0}};
	dest->object.specificites.triangle.ab = (t_vec){{0, 0, 0, 0}};
	dest->object.specificites.triangle.a_normal = (t_vec){{0, 0, 0, 0}};
	dest->object.specificites.triangle.b_normal = (t_vec){{0, 0, 0, 0}};
	dest->object.specificites.triangle.c_normal = (t_vec){{0, 0, 0, 0}};
	dest->object.specificites.triangle.a_uv = (t_vec2){{0, 0}};
	dest->object.specificites.triangle.b_uv = (t_vec2){{0, 0}};
	dest->object.specificites.triangle.c_uv = (t_vec2){{0, 0}};
	dest->object.specificites.triangle.has_vertex_normal = 0;
	dest->object.specificites.triangle.has_vertex_uv = 0;
}

void	ft_new_object_cylinder(t_object_info *dest)
{
	dest->object.type = cylinder;
	dest->object.specificites.cylinder.height = -1;
	dest->object.specificites.cylinder.diameter = -1;
}

void	ft_initialize_object_specificities(t_object_info *dest, int type)
{
	if (type == 0)
		ft_new_object_sphere(dest);
	else if (type == 1)
		ft_new_object_cone(dest);
	else if (type == 2)
		ft_new_object_cylinder(dest);
	else if (type == 3)
		ft_new_object_rounded_box(dest);
	else if (type == 4)
		ft_new_object_box(dest);
	else if (type == 6)
		ft_new_object_triangle(dest);
	else
		dest->object.type = plane;
}

t_object_info	*ft_new_object_json(int type)
{
	t_object_info	*dest;

	dest = ft_new_object();
	if (!dest)
		return (NULL);
	dest->object.color.t = 0;
	dest->object.coord.w = 0;
	dest->object.vec.w = 0;
	dest->object.reflection = -1;
	dest->object.transparency = -1;
	dest->object.refraction_indice = -1;
	dest->object.randomless = -1;
	dest->object.id_bump = -1;
	dest->object.id_texture = -1;
	ft_initialize_object_specificities(dest, type);
	return (dest);
}
