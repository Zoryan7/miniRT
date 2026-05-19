/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_r_box.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:59:13 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/06 13:17:31 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static float	ft_rbox_cast(t_rbox_trace *trace)
{
	int	state;

	while (trace->i < 56 && trace->t <= trace->t1)
	{
		state = ft_rbox_trace_step(trace);
		if (state == 1)
			return (trace->t);
		if (state == -1)
			break ;
		if (state == 2)
			return (ft_rbox_refine(trace));
		trace->i++;
	}
	return (-1.0f);
}

static float	ft_rbox_intersect(t_vec r_origin, t_vec r_dir, t_vec size,
		float radius)
{
	t_rbox_trace	trace;

	trace.r_origin = r_origin;
	trace.r_dir = r_dir;
	trace.size = size;
	trace.radius = radius;
	trace.bound_r = ft_vec_length(size) + radius + 0.001f;
	if (!ft_rbox_trace_start(&trace))
		return (-1.0f);
	return (ft_rbox_cast(&trace));
}

static t_vec2	ft_rbox_inside(t_rbox_hit *box)
{
	t_vec2	inter;

	inter.x = 0.0f;
	inter.y = ft_rbox_intersect(ft_rbox_point(box->ro_local, box->rd_local,
				0.001f), box->rd_local, box->half_size, box->radius);
	if (inter.y > 0.0f)
		inter.y += 0.001f;
	else
		inter.y = -1.0f;
	return (inter);
}

t_vec2	ft_intersect_r_box(t_ray ray, t_object obj)
{
	t_rbox_hit	box;
	t_vec2		inter;
	float		hit;

	ft_rbox_prepare(&box, ray, obj);
	if (box.sdf < 0.0f)
		return (ft_rbox_inside(&box));
	hit = ft_rbox_intersect(box.ro_local, box.rd_local, box.half_size,
			box.radius);
	if (hit == -1.0f)
		return ((t_vec2){{-1, -1}});
	inter.x = hit;
	inter.y = ft_rbox_intersect(ft_rbox_point(box.ro_local, box.rd_local,
				inter.x + 0.001f), box.rd_local, box.half_size, box.radius);
	if (inter.y > 0.0f)
		inter.y += inter.x + 0.001f;
	else
		inter.y = inter.x;
	return (inter);
}

float	ft_inter_button(t_vec r_origin, t_vec r_dir, t_vec size, float radius)
{
	return (ft_rbox_intersect(r_origin, r_dir, size, radius));
}
