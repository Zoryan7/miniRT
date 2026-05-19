/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:22:17 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:36:48 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

unsigned int	ft_get_pixel(char *addr, int line_length, int x, int y)
{
	char	*dst;

	dst = addr + (y * line_length + x * 4);
	return (*(unsigned int *)dst);
}

t_vec	ft_get_pixel_vec(char *addr, int line_lenght, int x, int y)
{
	unsigned int	color_int;
	t_vec			color_vec;

	color_int = ft_get_pixel(addr, line_lenght, x, y);
	color_vec.r = (float)((color_int >> 16) & 255) / 255.0f;
	color_vec.g = (float)((color_int >> 8) & 255) / 255.0f;
	color_vec.b = (float)(color_int & 255) / 255.0f;
	return (color_vec);
}

t_vec	ft_get_pixel_2(t_mini_rt *rt, int x, int y, t_vec color)
{
	if (rt->nb_img == 0)
	{
		rt->last_img[y * rt->info.width + x] = color;
		return (color);
	}
	rt->last_img[y * rt->info.width + x] = ft_gradient(rt->last_img[y
			* rt->info.width + x], color, 1.0f / (float)(rt->nb_img + 1));
	return (rt->last_img[y * rt->info.width + x]);
}

t_vec	ft_get_pixel_3(t_texture tex, float u, float v)
{
	t_info_get_pixel	info;

	info.uf = u * (tex.width - 1);
	info.vf = v * (tex.height - 1);
	info.x = (int)info.uf;
	info.y = (int)info.vf;
	info.dx = info.uf - (float)info.x;
	info.dy = info.vf - (float)info.y;
	info.x1 = ft_max(0, ft_min(info.x + 1, tex.width - 1));
	info.y1 = ft_max(0, ft_min(info.y + 1, tex.height - 1));
	info.c1 = ft_get_pixel_vec(tex.img.addr, tex.img.line_length, info.x,
			info.y);
	info.c2 = ft_get_pixel_vec(tex.img.addr, tex.img.line_length, info.x1,
			info.y);
	info.c3 = ft_get_pixel_vec(tex.img.addr, tex.img.line_length, info.x,
			info.y1);
	info.c4 = ft_get_pixel_vec(tex.img.addr, tex.img.line_length, info.x1,
			info.y1);
	info.c5 = ft_gradient(info.c1, info.c2, info.dx);
	info.c6 = ft_gradient(info.c3, info.c4, info.dx);
	return (ft_gradient(info.c5, info.c6, info.dy));
}
