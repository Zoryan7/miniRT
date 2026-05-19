/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_box.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:49:37 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 15:00:39 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"

t_vec2	ft_uv_box(t_object object, t_vec h)
{
	t_vec2	uv;
	t_aabb	box;
	float	dx;
	float	dy;
	float	dz;

	box = object.specificites.box.aabb;
	dx = box.max.x - box.min.x;
	dy = box.max.y - box.min.y;
	dz = box.max.z - box.min.z;
	if (fabs(h.x - box.min.x) < 0.001f)
		uv = (t_vec2){{(h.z - box.min.z) / dz, (h.y - box.min.y) / dy}};
	else if (fabs(h.x - box.max.x) < 0.001f)
		uv = (t_vec2){{1.0f - (h.z - box.min.z) / dz, (h.y - box.min.y) / dy}};
	else if (fabs(h.y - box.min.y) < 0.001f)
		uv = (t_vec2){{(h.x - box.min.x) / dx, (h.z - box.min.z) / dz}};
	else if (fabs(h.y - box.max.y) < 0.001f)
		uv = (t_vec2){{(h.x - box.min.x) / dx, 1.0f - (h.z - box.min.z) / dz}};
	else if (fabs(h.z - box.min.z) < 0.001f)
		uv = (t_vec2){{1.0f - (h.x - box.min.x) / dx, (h.y - box.min.y) / dy}};
	else
		uv = (t_vec2){{(h.x - box.min.x) / dx, (h.y - box.min.y) / dy}};
	return (ft_uv_clamp(uv));
}
