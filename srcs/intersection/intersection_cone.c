/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:06:10 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 06:03:17 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	ft_swap_t(float *a, float *b)
{
	float	temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

int	ft_cone_limit(t_vec2 *t, t_ray ray, const t_vec normal,
		const t_cone specficities)
{
	t_vec	hit_point;
	float	h;

	ft_swap_t(&t->x, &t->y);
	if (t->x > 0)
	{
		hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t->x));
		h = ft_vec_dot(ft_vec_sub(hit_point, specficities.apex), normal);
		if (h <= 0.001f && h >= -specficities.height - 0.001f)
		{
			t->y = t->x;
			return (0);
		}
	}
	else if (t->y > 0)
	{
		hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t->y));
		h = ft_vec_dot(ft_vec_sub(hit_point, specficities.apex), normal);
		if (h <= 0.001f && h >= -specficities.height - 0.001f)
			return (t->x = t->y, 0);
	}
	t->x = -1;
	t->y = -1;
	return (1);
}

static int	ft_is_in_disque_cone(t_ray ray, float t, t_vec center,
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
	if (d <= object.specificites.cone.radius * object.specificites.cone.radius)
		return (0);
	return (1);
}

t_vec2	ft_cone_cap(t_ray ray, t_vec2 t, t_object object)
{
	t_vec2	disk_t;

	disk_t = ft_intersect_plane(ray.origin, ray.direction, object.vec,
			-ft_vec_dot(object.coord, object.vec));
	if (ft_is_in_disque_cone(ray, disk_t.x, object.coord, object))
		disk_t = (t_vec2){{-1, -1}};
	ft_cone_limit(&t, ray, object.vec, object.specificites.cone);
	return (ft_chose_closest(t, disk_t));
}

t_vec2	ft_intersect_cone(t_ray ray, t_object object)
{
	float	p_cone;
	float	p_r_on_normal;
	t_vec2	t;
	t_vec	co;
	t_vec	cone_eq;

	co = ft_vec_sub(ray.origin, object.specificites.cone.apex);
	float (k) = object.specificites.cone.radius
		/ object.specificites.cone.height;
	k *= k;
	p_cone = ft_vec_dot(ray.direction, object.vec);
	p_r_on_normal = ft_vec_dot(co, object.vec);
	cone_eq.a = 1 - (1 + k) * p_cone * p_cone;
	if (ft_absf(cone_eq.a) == 0)
		return ((t_vec2){{-1, -1}});
	cone_eq.bb = 2 * (ft_vec_dot(ray.direction, co) - (1 + k) * p_r_on_normal
			* p_cone);
	cone_eq.c = ft_vec_dot(co, co) - (1 + k) * p_r_on_normal * p_r_on_normal;
	cone_eq.delta = cone_eq.bb * cone_eq.bb - 4 * cone_eq.a * cone_eq.c;
	if (cone_eq.delta < 0)
		return ((t_vec2){{-1, 0}});
	cone_eq.delta = sqrt(cone_eq.delta);
	t.x = (-cone_eq.bb - cone_eq.delta) / (2 * cone_eq.a);
	t.y = (-cone_eq.bb + cone_eq.delta) / (2 * cone_eq.a);
	return (ft_cone_cap(ray, t, object));
}
