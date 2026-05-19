/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:49:46 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 15:10:17 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"

t_vec2	ft_uv_plane(t_object object, t_vec hit_point)
{
	t_plane_info	info;

	info.scale = 40.0f;
	ft_uv_basis(object.vec, object.up_vec, (t_all_axis){&info.axis_x,
		&info.axis_y, &info.axis_z});
	info.local = ft_uv_to_local(ft_vec_sub(hit_point, object.coord),
			info.axis_x, info.axis_y, info.axis_z);
	info.uv.x = info.local.x / info.scale;
	info.uv.y = info.local.y / info.scale;
	return (ft_uv_wrap(info.uv));
}
