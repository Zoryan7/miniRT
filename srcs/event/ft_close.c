/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:03:28 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 02:47:40 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	ft_close(t_mini_rt *rt)
{
	int	i;

	pthread_mutex_lock(&rt->sync->mutex);
	rt->sync->pause = 0;
	pthread_cond_broadcast(&rt->sync->cond);
	pthread_mutex_unlock(&rt->sync->mutex);
	rt->end = 0;
	i = 0;
	while (i < sysconf(_SC_NPROCESSORS_ONLN - 1))
		pthread_join(rt->thread[i++], NULL);
	i = 0;
	while (i < rt->size_texture)
		mlx_destroy_image(rt->mlx, rt->texture[i++].img.img);
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_destroy_image(rt->mlx, rt->img.img);
	mlx_destroy_display(rt->mlx);
	pthread_mutex_destroy(&rt->sync->mutex);
	pthread_cond_destroy(&rt->sync->cond);
	if (rt->mlx)
		free(rt->mlx);
	ft_free_gc();
	exit(0);
	return (0);
}
