/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 02:50:04 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 05:32:06 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_vec	ft_bump_normal(t_mini_rt *rt, t_ray old_ray, t_calcul_color info)
{
	t_bump_info	i;

	i.hit_point = ft_vec_add(old_ray.origin, ft_vec_scale(old_ray.direction,
				info.dist_obj));
	i.uv = ft_uv_object(rt->object[info.ind_obj], i.hit_point);
	i.pix_color = ft_get_pixel_3(rt->texture[rt->object[info.ind_obj].id_bump],
			i.uv.x, i.uv.y);
	i.bump_color.r = (1.0f - i.pix_color.r) * 2.0f - 1.0f;
	i.bump_color.g = i.pix_color.g * 2.0f - 1.0f;
	i.bump_color.b = i.pix_color.b * 2.0f - 1.0f;
	if (fabs(old_ray.normal.y) < 0.999f)
		i.truc = (t_vec){{0, 1, 0}};
	else
		i.truc = (t_vec){{1, 0, 0}};
	i.tangent = ft_vec_normalize(ft_vec_cross(i.truc, old_ray.normal));
	i.bitangent = ft_vec_cross(old_ray.normal, i.tangent);
	i.new.v = i.bump_color.r * i.tangent.v + i.bump_color.g * i.bitangent.v
		+ i.bump_color.b * old_ray.normal.v;
	i.new = ft_vec_normalize(i.new);
	return (i.new);
}
