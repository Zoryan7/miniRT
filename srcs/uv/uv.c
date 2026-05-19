/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:48:16 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 14:55:15 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"

t_vec2	ft_uv_object(t_object object, t_vec hit_point)
{
	if (object.type == sphere || object.type == lights)
		return (ft_uv_sphere(object, hit_point));
	if (object.type == plane)
		return (ft_uv_plane(object, hit_point));
	if (object.type == triangle)
		return (ft_uv_triangle(object, hit_point));
	if (object.type == box)
		return (ft_uv_box(object, hit_point));
	if (object.type == rounded_box)
		return (ft_uv_rbox(object, hit_point));
	if (object.type == cylinder)
		return (ft_uv_cylinder(object, hit_point));
	if (object.type == cone)
		return (ft_uv_cone(object, hit_point));
	return ((t_vec2){{0.0f, 0.0f}});
}
