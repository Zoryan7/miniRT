/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:59:15 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 06:22:44 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_vec2	ft_chose_closest(t_vec2 t, t_vec2 t_bouchon)
{
	t_vec	all_t;
	float	min1;
	float	min2;
	int		i;

	ft_init_all_t(t, t_bouchon, &all_t);
	ft_init_min2_i(&min1, &min2, &i);
	while (i < 4)
	{
		if (all_t.v[i] > 0)
		{
			if (min1 < 0 || all_t.v[i] < min1)
				min2 = min1;
			if (min1 < 0 || all_t.v[i] < min1)
				min1 = all_t.v[i];
			else if (min2 < 0 || all_t.v[i] < min2)
				min2 = all_t.v[i];
		}
		i++;
	}
	if (min1 < 0)
		return ((t_vec2){{-1, 0}});
	if (min2 < 0)
		min2 = min1;
	return ((t_vec2){{min1, min2}});
}

static int	ft_cylinder_limit(t_vec2 *t, t_ray ray, t_object object)
{
	t_vec	hit_point;
	float	semi_h;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	semi_h = object.specificites.cylinder.height * 0.5f;
	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t->x));
	float (m) = ft_vec_dot(ft_vec_sub(hit_point, object.coord), object.vec);
	if (m >= -semi_h && m <= semi_h)
		i[0] = 1;
	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t->y));
	m = ft_vec_dot(ft_vec_sub(hit_point, object.coord), object.vec);
	if (m >= -semi_h && m <= semi_h)
		i[1] = 1;
	if (i[0] == 0 && i[1] == 0)
	{
		t->x = -1;
		t->y = -1;
	}
	else if (i[0] == 0)
		t->x = t->y;
	else if (i[1] == 0)
		t->y = t->x;
	return (0);
}

static int	ft_is_in_disque_cylinder(t_ray ray, float t, t_vec center,
		t_object object)
{
	t_vec	hit_point;
	t_vec	c_to_h;
	t_vec	proj;
	t_vec	perp;
	float	d;

	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t));
	c_to_h = ft_vec_sub(hit_point, center);
	proj = ft_vec_scale(object.vec, ft_vec_dot(c_to_h, object.vec));
	perp = ft_vec_sub(c_to_h, proj);
	d = ft_vec_dot(perp, perp);
	if (d <= object.specificites.cylinder.radius
		* object.specificites.cylinder.radius)
		return (0);
	return (1);
}

static t_vec2	ft_cylinder_caps(t_ray ray, t_object object, t_vec2 t)
{
	t_vec	center[2];
	t_vec2	temp;
	t_vec2	t_bouchon;

	center[0] = ft_vec_add(object.coord, ft_vec_scale(object.vec,
				object.specificites.cylinder.height * 0.5f));
	temp = ft_intersect_plane(ray.origin, ray.direction, object.vec,
			-ft_vec_dot(center[0], object.vec));
	t_bouchon.x = temp.x;
	center[1] = ft_vec_sub(object.coord, ft_vec_scale(object.vec,
				object.specificites.cylinder.height * 0.5f));
	temp = ft_intersect_plane(ray.origin, ray.direction, object.vec,
			-ft_vec_dot(center[1], object.vec));
	t_bouchon.y = temp.x;
	if (ft_is_in_disque_cylinder(ray, t_bouchon.x, center[0], object))
		t_bouchon.x = -1;
	if (ft_is_in_disque_cylinder(ray, t_bouchon.y, center[1], object))
		t_bouchon.y = -1;
	ft_cylinder_limit(&t, ray, object);
	return (ft_chose_closest(t, t_bouchon));
}

t_vec2	ft_intersect_cylinder(t_ray ray, t_object object)
{
	t_vec	eq;
	t_vec	oc;
	t_vec	direction;
	t_vec2	t;

	oc = ft_vec_sub(ray.origin, object.coord);
	direction = ft_vec_sub(ray.direction, ft_vec_scale(object.vec,
				ft_vec_dot(ray.direction, object.vec)));
	oc = ft_vec_sub(oc, ft_vec_scale(object.vec, ft_vec_dot(oc, object.vec)));
	eq.a = ft_vec_dot(direction, direction);
	eq.bb = ft_vec_dot(oc, direction) * 2.0f;
	eq.c = ft_vec_dot(oc, oc) - (object.specificites.cylinder.radius
			* object.specificites.cylinder.radius);
	eq.delta = eq.bb * eq.bb - 4.0f * eq.a * eq.c;
	if (eq.delta < 0)
		return ((t_vec2){{-1, 0}});
	eq.delta = sqrt(eq.delta);
	t.x = (-eq.bb - eq.delta) / (2 * eq.a);
	t.y = (-eq.bb + eq.delta) / (2 * eq.a);
	return (ft_cylinder_caps(ray, object, t));
}
