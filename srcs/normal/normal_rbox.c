/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_rbox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:53:46 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:10:34 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

static void	ft_rbox_basis(t_vec forward, t_vec up, t_all_axis axis)
{
	t_vec	fallback_up;

	if (ft_vec_length(forward) < 0.00001f)
		*axis.axis_z = (t_vec){{0, 0, 1, 0}};
	else
		*axis.axis_z = ft_vec_normalize(forward);
	if (ft_vec_length(up) < 0.00001f)
	{
		fallback_up = (t_vec){{0, 1, 0, 0}};
		if (ft_absf(ft_vec_dot(*axis.axis_z, fallback_up)) > 0.999f)
			fallback_up = (t_vec){{1, 0, 0, 0}};
	}
	else
		fallback_up = ft_vec_normalize(up);
	*axis.axis_x = ft_vec_cross(fallback_up, *axis.axis_z);
	float (cross_len) = ft_vec_length(*axis.axis_x);
	if (cross_len < 0.00001f)
	{
		fallback_up = (t_vec){{0, 1, 0, 0}};
		if (ft_absf(ft_vec_dot(*axis.axis_z, fallback_up)) > 0.999f)
			fallback_up = (t_vec){{1, 0, 0, 0}};
		*axis.axis_x = ft_vec_cross(fallback_up, *axis.axis_z);
	}
	*axis.axis_x = ft_vec_normalize(*axis.axis_x);
	*axis.axis_y = ft_vec_normalize(ft_vec_cross(*axis.axis_z, *axis.axis_x));
}

static t_vec	ft_to_rbox_local(t_vec p, t_vec axis_x, t_vec axis_y,
		t_vec axis_z)
{
	t_vec	out;

	out.x = ft_vec_dot(p, axis_x);
	out.y = ft_vec_dot(p, axis_y);
	out.z = ft_vec_dot(p, axis_z);
	out.t = 0;
	return (out);
}

static t_vec	ft_to_rbox_world(t_vec n, t_vec axis_x, t_vec axis_y,
		t_vec axis_z)
{
	t_vec	world;

	world = ft_vec_add(ft_vec_add(ft_vec_scale(axis_x, n.x),
				ft_vec_scale(axis_y, n.y)), ft_vec_scale(axis_z, n.z));
	world.t = 0;
	return (world);
}

t_vec	ft_normal_r_box(t_object object, float t, t_ray ray)
{
	t_info_rbox	i;

	ft_rbox_basis(object.vec, object.up_vec, (t_all_axis){&i.axis_x, &i.axis_y,
		&i.axis_z});
	i.ro_local = ft_to_rbox_local(ft_vec_sub(ray.origin, object.coord),
			i.axis_x, i.axis_y, i.axis_z);
	i.rd_local = ft_to_rbox_local(ray.direction, i.axis_x, i.axis_y, i.axis_z);
	i.hit_local = ft_vec_add(i.ro_local, ft_vec_scale(i.rd_local, t));
	i.normal.x = ft_maxf(ft_absf(i.hit_local.x)
			- object.specificites.rounded_box.size.x * 0.5f, 0.0f);
	i.normal.y = ft_maxf(ft_absf(i.hit_local.y)
			- object.specificites.rounded_box.size.y * 0.5f, 0.0f);
	i.normal.z = ft_maxf(ft_absf(i.hit_local.z)
			- object.specificites.rounded_box.size.z * 0.5f, 0.0f);
	i.normal.t = 0.0f;
	if (ft_vec_length(i.normal) < 0.00001f)
		i.normal = ft_vec_sign(i.hit_local);
	else
		i.normal = ft_vec_normalize(i.normal);
	i.normal = ft_vec_mult(i.normal, ft_vec_sign(i.hit_local));
	i.normal = ft_vec_normalize(ft_to_rbox_world(i.normal, i.axis_x, i.axis_y,
				i.axis_z));
	if (ft_vec_dot(i.normal, ray.direction) > 0)
		return (ft_vec_scale(i.normal, -1));
	return (i.normal);
}
