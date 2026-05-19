/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:49:48 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 14:55:17 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uv.h"

t_vec2	ft_uv_sphere(t_object object, t_vec hit_point)
{
	t_vec2	uv;
	t_vec	p;

	p = ft_vec_sub(hit_point, object.coord);
	p = ft_vec_normalize(p);
	uv.x = 0.5f + atan2(p.z, p.x) / (2.0f * M_PI);
	uv.y = 0.5f - asin(ft_clampf(p.y, -1.0f, 1.0f)) / M_PI;
	return (ft_uv_wrap_x(uv));
}
