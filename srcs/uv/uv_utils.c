/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:52:19 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 15:08:10 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"

void	ft_uv_basis(t_vec normal, t_vec up, t_all_axis axis)
{
	t_vec	fallback_up;

	if (ft_vec_length(normal) < 0.00001f)
		*axis.axis_z = (t_vec){{0, 1, 0, 0}};
	else
		*axis.axis_z = ft_vec_normalize(normal);
	if (ft_vec_length(up) < 0.00001f)
	{
		fallback_up = (t_vec){{0, 1, 0, 0}};
		if (ft_absf(ft_vec_dot(*axis.axis_z, fallback_up)) > 0.999f)
			fallback_up = (t_vec){{1, 0, 0, 0}};
	}
	else
		fallback_up = ft_vec_normalize(up);
	*axis.axis_x = ft_vec_cross(fallback_up, *axis.axis_z);
	if (ft_vec_length(*axis.axis_x) < 0.00001f)
	{
		fallback_up = (t_vec){{0, 1, 0, 0}};
		if (ft_absf(ft_vec_dot(*axis.axis_z, fallback_up)) > 0.999f)
			fallback_up = (t_vec){{1, 0, 0, 0}};
		*axis.axis_x = ft_vec_cross(fallback_up, *axis.axis_z);
	}
	*axis.axis_x = ft_vec_normalize(*axis.axis_x);
	*axis.axis_y = ft_vec_normalize(ft_vec_cross(*axis.axis_z, *axis.axis_x));
}

t_vec	ft_uv_to_local(t_vec p, t_vec axis_x, t_vec axis_y, t_vec axis_z)
{
	t_vec	local;

	local.x = ft_vec_dot(p, axis_x);
	local.y = ft_vec_dot(p, axis_y);
	local.z = ft_vec_dot(p, axis_z);
	local.t = 0.0f;
	return (local);
}

t_vec2	ft_uv_wrap(t_vec2 uv)
{
	uv.x = uv.x - floor(uv.x);
	uv.y = uv.y - floor(uv.y);
	return (uv);
}

t_vec2	ft_uv_wrap_x(t_vec2 uv)
{
	uv.x = uv.x - floor(uv.x);
	uv.y = ft_clampf(uv.y, 0.0f, 1.0f);
	return (uv);
}

t_vec2	ft_uv_clamp(t_vec2 uv)
{
	uv.x = ft_clampf(uv.x, 0.0f, 1.0f);
	uv.y = ft_clampf(uv.y, 0.0f, 1.0f);
	return (uv);
}
