/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:49:39 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 15:11:39 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"

t_vec2	ft_uv_cone(t_object object, t_vec hit_point)
{
	t_vec	axis_x;
	t_vec	axis_y;
	t_vec	axis_z;
	t_vec	local;
	t_vec2	uv;

	ft_uv_basis(object.vec, (t_vec){{0, 1, 0, 0}}, (t_all_axis){&axis_x,
		&axis_y, &axis_z});
	local = ft_uv_to_local(ft_vec_sub(hit_point, object.specificites.cone.apex),
			axis_x, axis_y, axis_z);
	if (fabs(local.z + object.specificites.cone.height) < 0.001f)
	{
		uv.x = (local.x / object.specificites.cone.radius) * 0.5f + 0.5f;
		uv.y = (local.y / object.specificites.cone.radius) * 0.5f + 0.5f;
		return (ft_uv_clamp(uv));
	}
	uv.x = 0.5f + atan2(local.y, local.x) / (2.0f * M_PI);
	uv.y = (-local.z) / object.specificites.cone.height;
	return (ft_uv_wrap_x((t_vec2){{uv.x, ft_clampf(uv.y, 0.0f, 1.0f)}}));
}
