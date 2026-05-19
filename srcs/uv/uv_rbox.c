/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_rbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:49:44 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 15:11:48 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"

t_vec2	ft_uv_rbox(t_object object, t_vec hit_point)
{
	t_rbox_info	i;

	ft_uv_basis(object.vec, object.up_vec, (t_all_axis){&i.axis_x, &i.axis_y,
		&i.axis_z});
	i.local = ft_uv_to_local(ft_vec_sub(hit_point, object.coord), i.axis_x,
			i.axis_y, i.axis_z);
	i.half = ft_vec_scale(object.specificites.rounded_box.size, 0.5f);
	i.extent = ft_vec_add(i.half,
			(t_vec){{object.specificites.rounded_box.radius,
			object.specificites.rounded_box.radius,
			object.specificites.rounded_box.radius, 0.0f}});
	i.axis_score_x = ft_absf(i.local.x) / ft_maxf(i.extent.x, 0.00001f);
	i.axis_score_y = ft_absf(i.local.y) / ft_maxf(i.extent.y, 0.00001f);
	i.axis_score_z = ft_absf(i.local.z) / ft_maxf(i.extent.z, 0.00001f);
	if (i.axis_score_x >= i.axis_score_y && i.axis_score_x >= i.axis_score_z)
		i.uv = (t_vec2){{0.5f - (i.local.z / i.extent.z) * 0.5f, (i.local.y
				/ i.extent.y) * 0.5f + 0.5f}};
	else if (i.axis_score_y >= i.axis_score_z)
		i.uv = (t_vec2){{(i.local.x / i.extent.x) * 0.5f + 0.5f, 0.5f
			- (i.local.z / i.extent.z) * 0.5f}};
	else
		i.uv = (t_vec2){{(i.local.x / i.extent.x) * 0.5f + 0.5f, (i.local.y
				/ i.extent.y) * 0.5f + 0.5f}};
	return (ft_uv_clamp(i.uv));
}
