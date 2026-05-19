/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:51:30 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 08:39:37 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

t_vec	ft_choose_normal(t_object object, float t, t_ray ray)
{
	if (object.type == sphere || object.type == lights)
		return (ft_normal_sphere(object, t, ray));
	else if (object.type == plane)
		return (ft_normal_plane(object, ray));
	else if (object.type == triangle)
		return (ft_normal_triangle(object, t, ray));
	else if (object.type == rounded_box)
		return (ft_normal_r_box(object, t, ray));
	else if (object.type == box)
		return (ft_normal_box(object.specificites.box.aabb, t, ray));
	else if (object.type == cone)
		return (ft_normal_cone(object, t, ray));
	if (object.type == cylinder)
		return (ft_normal_cylinder(object, t, ray));
	return ((t_vec){{-1, -1, -1, 0}});
}
