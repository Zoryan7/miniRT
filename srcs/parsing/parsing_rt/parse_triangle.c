/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 09:25:40 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 09:25:59 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

void	ft_initialize_triangle(t_object_info *object)
{
	object->object.specificites.triangle.a = (t_vec){{0, 0, 0, 0}};
	object->object.specificites.triangle.b = (t_vec){{0, 0, 0, 0}};
	object->object.specificites.triangle.c = (t_vec){{0, 0, 0, 0}};
	object->object.specificites.triangle.ac = (t_vec){{0, 0, 0, 0}};
	object->object.specificites.triangle.ab = (t_vec){{0, 0, 0, 0}};
	object->object.specificites.triangle.a_normal = (t_vec){{0, 0, 0, 0}};
	object->object.specificites.triangle.b_normal = (t_vec){{0, 0, 0, 0}};
	object->object.specificites.triangle.c_normal = (t_vec){{0, 0, 0, 0}};
	object->object.specificites.triangle.a_uv = (t_vec2){{0, 0}};
	object->object.specificites.triangle.b_uv = (t_vec2){{0, 0}};
	object->object.specificites.triangle.c_uv = (t_vec2){{0, 0}};
	object->object.specificites.triangle.has_vertex_normal = 0;
	object->object.specificites.triangle.has_vertex_uv = 0;
}

int	ft_parse_triangle_vec(char *line, t_object_info *object, int *i)
{
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_triple_recup_float_2(line,
			&object->object.specificites.triangle.a_normal, i)
		|| ft_check_normalize(object->object.specificites.triangle.a_normal))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_triple_recup_float_2(line,
			&object->object.specificites.triangle.b_normal, i)
		|| ft_check_normalize(object->object.specificites.triangle.b_normal))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_triple_recup_float_2(line,
			&object->object.specificites.triangle.c_normal, i)
		|| ft_check_normalize(object->object.specificites.triangle.c_normal))
		return (1);
	return (0);
}

int	ft_parse_triangle_uv(char *line, t_object_info *object, int *i)
{
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.triangle.a_uv.x, i,
			1))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.triangle.a_uv.y, i,
			2))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.triangle.b_uv.x, i,
			1))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.triangle.b_uv.y, i,
			2))
		return (1);
	if (ft_skip_space(i, line, 0))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.triangle.c_uv.x, i,
			1))
		return (1);
	if (ft_recup_float(line, &object->object.specificites.triangle.c_uv.y, i,
			2))
		return (1);
	return (0);
}

int	ft_parse_triangle_specificities(char *line, t_object_info *object, int *i)
{
	t_vec	temp;

	ft_initialize_triangle(object);
	object->object.type = triangle;
	object->object.specificites.triangle.a = object->object.coord;
	if (ft_triple_recup_float_1(line, &object->object.specificites.triangle.b,
			i) || ft_skip_space(i, line, 0) || ft_triple_recup_float_1(line,
			&object->object.specificites.triangle.c, i))
		return (1);
	temp = object->object.specificites.triangle.c;
	object->object.specificites.triangle.ac.v = temp.v
		- object->object.specificites.triangle.a.v;
	temp = object->object.specificites.triangle.b;
	object->object.specificites.triangle.ab.v = temp.v
		- object->object.specificites.triangle.a.v;
	temp = ft_vec_cross(object->object.specificites.triangle.ab,
			object->object.specificites.triangle.ac);
	if (ft_parse_triangle_vec(line, object, i))
		return (1);
	if (ft_parse_triangle_uv(line, object, i))
		return (1);
	object->object.specificites.triangle.has_vertex_normal = 1;
	object->object.specificites.triangle.has_vertex_uv = 1;
	object->object.vec = ft_vec_normalize(temp);
	return (object->object.init_vec = object->object.vec, 0);
}
