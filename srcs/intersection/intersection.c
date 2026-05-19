/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:01:12 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/10 10:29:03 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

// static t_vec2 ft_intersect_plane(const t_vec r_origin, const t_vec r_dir,
// const t_vec plane_normal, const float plane_distance)
// {
// 	float	t;

// 	t = ft_vec_dot(r_dir, plane_normal);
// 	if (ft_absf(t) == 0)
// 		return ((t_vec2){{-1, 0}});
// 	t = (ft_vec_dot (r_origin, plane_normal) + plane_distance) / t;
// 	return((t_vec2){{t, t}});
// }

t_vec2	ft_intersect_plane(const t_vec r_origin, const t_vec r_dir,
		const t_vec p, const float p_y)
{
	float	t;

	t = ft_vec_dot(r_dir, p);
	if (ft_absf(t) == 0)
		return ((t_vec2){{-1, 0}});
	t = -((ft_vec_dot(r_origin, p) + p_y) / ft_vec_dot(r_dir, p));
	return ((t_vec2){{t, t}});
}

static t_vec2	ft_intersect_sphere(const t_vec r_origin, const t_vec r_dir,
		const t_vec sp_coord, const float radius)
{
	t_vec	oc;
	t_vec	qc;
	float	h;
	float	b;

	oc.v = r_origin.v - sp_coord.v;
	b = ft_vec_dot(oc, r_dir);
	qc.v = oc.v - b * r_dir.v;
	h = radius * radius - ft_vec_dot(qc, qc);
	if (h < 0.001f)
		return ((t_vec2){{-1, 0}});
	h = sqrt(h);
	return ((t_vec2){{-b - h, -b + h}});
}

static t_vec2	ft_intersect_triangle(t_ray ray, t_object object)
{
	t_vec	h;
	t_vec	temp;
	float	a;
	float	barycentric[2];
	float	t;

	h = ft_vec_cross(ray.direction, object.specificites.triangle.ac);
	a = ft_vec_dot(object.specificites.triangle.ab, h);
	if (ft_absf(a) < 0.001f)
		return ((t_vec2){{-1, 0}});
	a = 1.0f / a;
	temp.v = ray.origin.v - object.specificites.triangle.a.v;
	barycentric[0] = a * ft_vec_dot(temp, h);
	if (barycentric[0] < 0.0f || barycentric[0] > 1.0f)
		return ((t_vec2){{-1, 0}});
	temp = ft_vec_cross(temp, object.specificites.triangle.ab);
	barycentric[1] = a * ft_vec_dot(ray.direction, temp);
	if (barycentric[1] < 0.0f || barycentric[0] + barycentric[1] > 1.0f)
		return ((t_vec2){{-1, 0}});
	t = a * ft_vec_dot(object.specificites.triangle.ac, temp);
	if (t <= 0.001f)
		return ((t_vec2){{-1, 0}});
	return ((t_vec2){{t, t}});
}

t_vec2	ft_choose_intersect(t_object object, t_ray ray)
{
	if (object.type == sphere)
		return (ft_intersect_sphere(ray.origin, ray.direction, object.coord,
				object.specificites.sphere.radius));
	else if (object.type == lights)
		return (ft_intersect_sphere(ray.origin, ray.direction, object.coord,
				object.specificites.lights.radius));
	else if (object.type == plane)
		return (ft_intersect_plane(ray.origin, ray.direction, object.vec,
				-object.coord.y));
	else if (object.type == cylinder)
		return (ft_intersect_cylinder(ray, object));
	else if (object.type == box)
		return (ft_intersect_box(ray, object.specificites.box.aabb));
	else if (object.type == cone)
		return (ft_intersect_cone(ray, object));
	else if (object.type == rounded_box)
		return (ft_intersect_r_box(ray, object));
	else if (object.type == triangle)
		return (ft_intersect_triangle(ray, object));
	else
		return ((t_vec2){{-1, -1}});
}
