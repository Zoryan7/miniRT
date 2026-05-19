/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:18:40 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:36:44 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_take_task(t_mini_rt *rt, int *mode, int *task_id)
{
	if (rt->blur_done == 0 && rt->cur_task < rt->info.height)
	{
		*mode = 1;
		*task_id = rt->cur_task++;
	}
	else if (rt->blur_done == 1 && rt->cur_task < rt->info.height)
	{
		*mode = 2;
		*task_id = rt->cur_task++;
	}
	else if (rt->blur_done == 2 && rt->cur_task < rt->info.width)
	{
		*mode = 3;
		*task_id = rt->cur_task++;
	}
}

static void	ft_do_task(t_mini_rt *rt, int mode, int task_id, float *gauss_tab)
{
	if (mode == 1)
		ft_draw_thread(rt, rt->task[task_id]);
	else if (mode == 2)
		ft_horizontal_task(rt, rt->task[task_id], gauss_tab);
	else if (mode == 3)
		ft_vertical_task(rt, rt->task_v[task_id], gauss_tab);
}

void	*ft_routine(void *arg)
{
	t_mini_rt	*rt;
	float		*gauss_tab;
	int			mode;
	int			task_id;

	rt = (t_mini_rt *)arg;
	gauss_tab = ft_gauss();
	while (rt->end)
	{
		pthread_mutex_lock(&rt->sync->mutex);
		while (rt->sync->pause)
			pthread_cond_wait(&rt->sync->cond, &rt->sync->mutex);
		mode = 0;
		task_id = -1;
		ft_take_task(rt, &mode, &task_id);
		pthread_mutex_unlock(&rt->sync->mutex);
		if (task_id == -1)
		{
			usleep(100);
			continue ;
		}
		ft_do_task(rt, mode, task_id, gauss_tab);
		rt->done_task++;
	}
	return (NULL);
}

void	ft_release_thread(t_mini_rt *rt)
{
	pthread_mutex_lock(&rt->sync->mutex);
	rt->sync->pause = 0;
	pthread_cond_broadcast(&rt->sync->cond);
	pthread_mutex_unlock(&rt->sync->mutex);
}

void	ft_block_thread(t_mini_rt *rt)
{
	pthread_mutex_lock(&rt->sync->mutex);
	rt->sync->pause = 1;
	pthread_mutex_unlock(&rt->sync->mutex);
}
