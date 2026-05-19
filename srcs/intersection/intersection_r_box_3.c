/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_r_box_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:17:42 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/10 10:28:38 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	ft_rbox_prepare(t_rbox_hit *box, t_ray ray, t_object obj)
{
	ft_rbox_basis_i(&box->basis, obj.vec, obj.up_vec);
	box->ro_local = ft_to_rbox_local_i(ft_vec_sub(ray.origin, obj.coord),
			box->basis);
	box->rd_local = ft_to_rbox_local_i(ray.direction, box->basis);
	box->half_size = ft_vec_divide(obj.specificites.rounded_box.size, 2);
	box->radius = obj.specificites.rounded_box.radius;
	box->sdf = ft_rbox_sdf(box->ro_local, box->half_size, box->radius);
	box->hit = -1.0f;
}

int	ft_rbox_trace_start(t_rbox_trace *trace)
{
	trace->a = ft_vec_dot(trace->r_dir, trace->r_dir);
	if (trace->a == 0.0f)
		return (0);
	trace->b = ft_vec_dot(trace->r_origin, trace->r_dir);
	trace->c = ft_vec_dot(trace->r_origin, trace->r_origin) - trace->bound_r
		* trace->bound_r;
	trace->h = trace->b * trace->b - trace->a * trace->c;
	if (trace->h < 0.0f)
		return (0);
	trace->h = sqrt(trace->h);
	trace->t0 = (-trace->b - trace->h) / trace->a;
	trace->t1 = (-trace->b + trace->h) / trace->a;
	if (trace->t1 <= 0.00001f)
		return (0);
	trace->t = 0.00001f;
	if (trace->t0 > trace->t)
		trace->t = trace->t0;
	trace->d = ft_rbox_sdf(ft_rbox_point(trace->r_origin, trace->r_dir,
				trace->t), trace->size, trace->radius);
	trace->i = 0;
	return (1);
}

int	ft_rbox_trace_step(t_rbox_trace *trace)
{
	if (ft_absf(trace->d) < 0.0002f)
		return (1);
	trace->step = ft_maxf(ft_absf(trace->d) * 0.85f, 0.0001f);
	trace->t_prev = trace->t;
	trace->d_prev = trace->d;
	trace->t += trace->step;
	if (trace->t > trace->t1)
		return (-1);
	trace->d = ft_rbox_sdf(ft_rbox_point(trace->r_origin, trace->r_dir,
				trace->t), trace->size, trace->radius);
	if ((trace->d_prev <= 0.0f && trace->d >= 0.0f) || (trace->d_prev >= 0.0f
			&& trace->d <= 0.0f))
		return (2);
	return (0);
}

float	ft_rbox_refine(t_rbox_trace *trace)
{
	trace->lo = trace->t_prev;
	trace->hi = trace->t;
	trace->i = 0;
	while (trace->i < 14)
	{
		trace->mid = 0.5f * (trace->lo + trace->hi);
		trace->d_mid = ft_rbox_sdf(ft_rbox_point(trace->r_origin, trace->r_dir,
					trace->mid), trace->size, trace->radius);
		if ((trace->d_prev <= 0.0f && trace->d_mid <= 0.0f)
			|| (trace->d_prev >= 0.0f && trace->d_mid >= 0.0f))
			trace->lo = trace->mid;
		else
			trace->hi = trace->mid;
		trace->i++;
	}
	return (0.5f * (trace->lo + trace->hi));
}
