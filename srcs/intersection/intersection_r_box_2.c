/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_r_box_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:16:16 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/10 10:28:41 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_vec	ft_rbox_fallback_up(t_vec axis_z, t_vec up)
{
	t_vec	fallback_up;

	if (ft_vec_length(up) < 0.00001f)
	{
		fallback_up = (t_vec){{0, 1, 0, 0}};
		if (ft_absf(ft_vec_dot(axis_z, fallback_up)) > 0.999f)
			fallback_up = (t_vec){{1, 0, 0, 0}};
	}
	else
		fallback_up = ft_vec_normalize(up);
	return (fallback_up);
}

void	ft_rbox_basis_i(t_rbox_basis *basis, t_vec forward, t_vec up)
{
	if (ft_vec_length(forward) < 0.00001f)
		basis->axis_z = (t_vec){{0, 0, 1, 0}};
	else
		basis->axis_z = ft_vec_normalize(forward);
	up = ft_rbox_fallback_up(basis->axis_z, up);
	basis->axis_x = ft_vec_cross(up, basis->axis_z);
	if (ft_vec_length(basis->axis_x) < 0.00001f)
	{
		up = ft_rbox_fallback_up(basis->axis_z, (t_vec){{0, 1, 0, 0}});
		basis->axis_x = ft_vec_cross(up, basis->axis_z);
	}
	basis->axis_x = ft_vec_normalize(basis->axis_x);
	basis->axis_y = ft_vec_cross(basis->axis_z, basis->axis_x);
	basis->axis_y = ft_vec_normalize(basis->axis_y);
}

t_vec	ft_to_rbox_local_i(t_vec p, t_rbox_basis basis)
{
	t_vec	out;

	out.x = ft_vec_dot(p, basis.axis_x);
	out.y = ft_vec_dot(p, basis.axis_y);
	out.z = ft_vec_dot(p, basis.axis_z);
	out.t = 0;
	return (out);
}

t_vec	ft_rbox_point(t_vec origin, t_vec dir, float t)
{
	return (ft_vec_add(origin, ft_vec_scale(dir, t)));
}

float	ft_rbox_sdf(t_vec p, t_vec half_size, float radius)
{
	t_vec	q;
	t_vec	out;

	q.x = ft_absf(p.x) - half_size.x;
	q.y = ft_absf(p.y) - half_size.y;
	q.z = ft_absf(p.z) - half_size.z;
	q.t = 0;
	out.x = ft_maxf(q.x, 0.0f);
	out.y = ft_maxf(q.y, 0.0f);
	out.z = ft_maxf(q.z, 0.0f);
	out.t = 0;
	return (ft_vec_length(out) + ft_minf(ft_maxf(ft_maxf(q.x, q.y), q.z), 0.0f)
		- radius);
}
