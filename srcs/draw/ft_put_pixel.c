/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:31:13 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:42:08 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec	ft_tone_mapping(t_vec color, t_mini_rt *rt)
{
	t_vec	tone_color;
	float	avg;

	tone_color.r = color.r * rt->info.exposure;
	tone_color.g = color.g * rt->info.exposure;
	tone_color.b = color.b * rt->info.exposure;
	tone_color.r = (tone_color.r * (1.0f + tone_color.r / (rt->info.white
					* rt->info.white))) / (1.0f + tone_color.r);
	tone_color.g = (tone_color.g * (1.0f + tone_color.g / (rt->info.white
					* rt->info.white))) / (1.0f + tone_color.g);
	tone_color.b = (tone_color.b * (1.0f + tone_color.b / (rt->info.white
					* rt->info.white))) / (1.0f + tone_color.b);
	tone_color.r = pow(tone_color.r, 1.0f / 2.2f);
	tone_color.g = pow(tone_color.g, 1.0f / 2.2f);
	tone_color.b = pow(tone_color.b, 1.0f / 2.2f);
	avg = (tone_color.r + tone_color.g + tone_color.b) / 3.0;
	tone_color.r = avg + (tone_color.r - avg) * rt->info.saturation;
	tone_color.g = avg + (tone_color.g - avg) * rt->info.saturation;
	tone_color.b = avg + (tone_color.b - avg) * rt->info.saturation;
	return (tone_color);
}

t_vec	ft_hdr(t_vec color)
{
	t_vec	hdr_color;

	hdr_color.r = ft_minf(color.r, 1);
	hdr_color.g = ft_minf(color.g, 1);
	hdr_color.b = ft_minf(color.b, 1);
	return (hdr_color);
}

void	ft_put_pixel(t_mini_rt *rt, int x, int y, t_vec color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= rt->info.width || y >= rt->info.height)
		return ;
	dst = &rt->img.addr[y * rt->img.line_length + x * 4];
	if (rt->tone_on == 1)
		color = ft_tone_mapping(color, rt);
	else
		color = ft_hdr(color);
	*(unsigned int *)dst = (int)(color.r * 255) << 16 | (int)(color.g
			* 255) << 8 | (int)(color.b * 255);
}
