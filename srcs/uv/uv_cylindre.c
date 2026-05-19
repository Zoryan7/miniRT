/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_cylindre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:49:41 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 15:11:27 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"

t_vec2	ft_uv_cylinder(t_object object, t_vec hit_point)
{
	t_cylindre_info	info;

	ft_uv_basis(object.vec, (t_vec){{0, 1, 0, 0}}, (t_all_axis){&info.axis_x,
		&info.axis_y, &info.axis_z});
	info.local = ft_uv_to_local(ft_vec_sub(hit_point, object.coord),
			info.axis_x, info.axis_y, info.axis_z);
	info.height = object.specificites.cylinder.height;
	if (fabs(fabs(info.local.z) - info.height * 0.5f) < 0.001f)
	{
		info.uv.x = (info.local.x / object.specificites.cylinder.radius) * 0.5f
			+ 0.5f;
		info.uv.y = (info.local.y / object.specificites.cylinder.radius) * 0.5f
			+ 0.5f;
		return (ft_uv_clamp(info.uv));
	}
	info.uv.x = 0.5f + atan2(info.local.y, info.local.x) / (2.0f * M_PI);
	info.uv.y = (info.local.z / info.height) + 0.5f;
	return (ft_uv_wrap_x((t_vec2){{info.uv.x, ft_clampf(info.uv.y, 0.0f,
					1.0f)}}));
}
