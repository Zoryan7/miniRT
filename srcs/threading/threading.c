/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:14:57 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/14 13:51:20 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threading.h"

void	ft_init_thread(t_mini_rt *rt)
{
	int	i;

	rt->thread = ft_gc_malloc(sysconf(_SC_NPROCESSORS_ONLN - 1),
			sizeof(pthread_t), rt_type);
	i = 0;
	while (i < sysconf(_SC_NPROCESSORS_ONLN - 1))
	{
		pthread_create(&rt->thread[i], NULL, &ft_routine, rt);
		usleep(10);
		i++;
	}
}

// void	ft_init_thread(t_mini_rt *rt)
// {
// 	int	i;

// 	rt->thread = ft_gc_malloc(12,
// 			sizeof(pthread_t), rt_type);
// 	i = 0;
// 	while (i < 12)
// 	{
// 		pthread_create(&rt->thread[i], NULL, &ft_routine, rt);
// 		usleep(10);
// 		i++;
// 	}
// }

void	ft_init_task(t_mini_rt *rt)
{
	int	i;

	rt->cur_task = rt->info.height - 1;
	rt->end = 1;
	rt->sync = ft_gc_malloc(1, sizeof(t_sync), rt_type);
	pthread_mutex_init(&rt->sync->mutex, NULL);
	pthread_cond_init(&rt->sync->cond, NULL);
	rt->sync->pause = 1;
	rt->task = ft_gc_malloc(rt->info.height, sizeof(t_task), rt_type);
	rt->task_v = ft_gc_malloc(rt->info.width, sizeof(t_task), rt_type);
	i = 0;
	while (i < rt->info.height)
	{
		rt->task[i] = ft_create_task(i);
		i++;
	}
	i = 0;
	while (i < rt->info.width)
	{
		rt->task_v[i] = ft_create_task_v(i);
		i++;
	}
}

void	ft_resize_task_arrays(t_mini_rt *rt)
{
	int	i;

	if (rt->task)
		free(rt->task);
	if (rt->task_v)
		free(rt->task_v);
	rt->task = ft_gc_malloc(sizeof(t_task), rt->info.height, rt_type);
	rt->task_v = ft_gc_malloc(sizeof(t_task), rt->info.width, rt_type);
	if (!rt->task || !rt->task_v)
		return ;
	i = 0;
	while (i < rt->info.height)
	{
		rt->task[i] = ft_create_task(i);
		i++;
	}
	i = 0;
	while (i < rt->info.width)
	{
		rt->task_v[i] = ft_create_task_v(i);
		i++;
	}
}

t_task	ft_create_task(int i)
{
	t_task	task;

	task.y = i;
	task.x = 0;
	return (task);
}

t_task	ft_create_task_v(int i)
{
	t_task	task;

	task.x = i;
	task.y = 0;
	return (task);
}
