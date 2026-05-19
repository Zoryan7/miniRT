/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:53:28 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 03:55:17 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

t_vec	ft_normal_box(t_aabb box, float t, t_ray ray)
{
	t_vec	hit_point;

	hit_point = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, t));
	if (fabs(hit_point.x - box.min.x) < 0.001f)
		return ((t_vec){{-1.0f, 0.0f, 0.0f}});
	if (fabs(hit_point.x - box.max.x) < 0.001f)
		return ((t_vec){{1.0f, 0.0f, 0.0f}});
	if (fabs(hit_point.y - box.min.y) < 0.001f)
		return ((t_vec){{0.0f, -1.0f, 0.0f}});
	if (fabs(hit_point.y - box.max.y) < 0.001f)
		return ((t_vec){{0.0f, 1.0f, 0.0f}});
	if (fabs(hit_point.z - box.min.z) < 0.001f)
		return ((t_vec){{0.0f, 0.0f, -1.0f}});
	if (fabs(hit_point.z - box.max.z) < 0.001f)
		return ((t_vec){{0.0f, 0.0f, 1.0f}});
	return ((t_vec){{0.0f, 0.0f, 0.0f}});
}
