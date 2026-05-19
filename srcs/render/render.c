/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:38:48 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 05:51:00 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_render_moov_view(t_mini_rt *rt, unsigned long elapsed)
{
	if (rt->page == 0)
	{
		ft_mouse_move(rt);
		if (rt->selec == __INT_MAX__)
			ft_moov(rt, elapsed);
		else if (rt->page == 0)
			ft_moov_obj(rt, elapsed);
	}
	if (rt->nb_img == 0)
		ft_calcul_viewport(rt);
}

static void	ft_render_jitter(t_mini_rt *rt)
{
	if (rt->nb_img > 2)
	{
		rt->camera.rand_x = ft_rand();
		rt->camera.rand_y = ft_rand();
	}
	else
	{
		rt->camera.rand_x = 0;
		rt->camera.rand_y = 0;
	}
}

static void	ft_render_blur(t_mini_rt *rt)
{
	if (rt->blur_done == 1)
		rt->blur_done = 2;
	else if (rt->blur_done == 2)
		rt->blur_done = 3;
	if (rt->blur_done != 1)
		mlx_put_image_to_window(rt->mlx, rt->win, rt->img.img, 0, 0);
}

static void	ft_render_text(t_mini_rt *rt, unsigned long elapsed)
{
	if (rt->page == 0 && rt->rot_on == 1)
		ft_gui(rt, elapsed);
	if (rt->page == 1)
		ft_control_page(rt);
	if (rt->page == 2 || rt->page == 3 || rt->page == 4 || rt->page == 5)
		ft_general_page(rt);
	ft_crosshair(rt);
}

int	ft_render(t_mini_rt *rt)
{
	static unsigned long	last_time = 0;
	int						jobs_to_wait;

	unsigned long (time) = ft_get_utime();
	unsigned long (elapsed) = time - last_time;
	last_time = time;
	ft_render_moov_view(rt, elapsed);
	ft_render_jitter(rt);
	rt->done_task = 0;
	rt->cur_task = 0;
	jobs_to_wait = 0;
	if (rt->blur_done == 0)
		jobs_to_wait = rt->info.height;
	else if (rt->blur_done == 1)
		jobs_to_wait = rt->info.height;
	else if (rt->blur_done == 2)
		jobs_to_wait = rt->info.width;
	ft_release_thread(rt);
	while (rt->done_task < jobs_to_wait)
		usleep(50);
	ft_block_thread(rt);
	rt->nb_img++;
	ft_render_blur(rt);
	ft_render_text(rt, elapsed);
	return (0);
}
