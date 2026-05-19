/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:16:52 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 15:48:29 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_horizontal_task(t_mini_rt *rt, t_task task, float *gauss_tab)
{
	char	*tmp;

	tmp = malloc(rt->info.height * rt->img.line_length + rt->info.width * 4);
	ft_memcpy(tmp, rt->img.addr, rt->info.height * rt->img.line_length
		+ rt->info.width * 4);
	while (task.x <= rt->info.width)
	{
		ft_horizontal_blur_thread(rt, gauss_tab, task, tmp);
		task.x++;
	}
	free(tmp);
}

void	ft_vertical_task(t_mini_rt *rt, t_task task, float *gauss_tab)
{
	char	*tmp;

	tmp = malloc(rt->info.height * rt->img.line_length + rt->info.width * 4);
	ft_memcpy(tmp, rt->img.addr, rt->info.height * rt->img.line_length
		+ rt->info.width * 4);
	while (task.y <= rt->info.height)
	{
		ft_vertical_blur_thread(rt, gauss_tab, task, tmp);
		task.y++;
	}
	free(tmp);
}

void	ft_horizontal_blur_thread(t_mini_rt *rt, float *gauss_tab, t_task task,
		char *tmp)
{
	int				dx;
	int				radius;
	unsigned int	pix_color;
	t_vec			color;

	color = (t_vec){{0.0f, 0.0f, 0.0f, 0.0f}};
	radius = GAUSS_RADIUS;
	dx = -radius;
	while (dx <= radius)
	{
		if (task.x + dx < 0 || task.x + dx >= rt->info.width)
		{
			dx++;
			continue ;
		}
		pix_color = ft_get_pixel(tmp, rt->img.line_length, task.x + dx, task.y);
		color.r += (float)((pix_color >> 16) & 255) / 255 * (float)gauss_tab[dx
			+ radius];
		color.g += (float)((pix_color >> 8) & 255) / 255 * (float)gauss_tab[dx
			+ radius];
		color.b += (float)(pix_color & 255) / 255 * (float)gauss_tab[dx
			+ radius];
		dx++;
	}
	ft_put_pixel(rt, task.x, task.y, color);
}

void	ft_vertical_blur_thread(t_mini_rt *rt, float *gauss_tab, t_task task,
		char *tmp)
{
	int				dy;
	int				radius;
	unsigned int	pix_color;
	t_vec			color;

	color = (t_vec){{0.0f, 0.0f, 0.0f, 0.0f}};
	radius = GAUSS_RADIUS;
	dy = -radius;
	while (dy <= radius)
	{
		if (task.y + dy < 0 || task.y + dy >= rt->info.height)
		{
			dy++;
			continue ;
		}
		pix_color = ft_get_pixel(tmp, rt->img.line_length, task.x, task.y + dy);
		color.r += (float)((pix_color >> 16) & 255) / 255 * gauss_tab[dy
			+ radius];
		color.g += (float)((pix_color >> 8) & 255) / 255 * gauss_tab[dy
			+ radius];
		color.b += (float)(pix_color & 255) / 255 * gauss_tab[dy + radius];
		dy++;
	}
	ft_put_pixel(rt, task.x, task.y, color);
}
