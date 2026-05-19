/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:27:47 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/06 11:35:08 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static int	ft_verif_speed_sensi(char *arg)
{
	if (ft_atof(arg) < 0)
		return (0);
	return (1);
}

static int	ft_verif_fov(char *fov)
{
	if (ft_atoi(fov) > 180 || ft_atoi(fov) <= 0)
		return (0);
	return (1);
}

static int	ft_verif_bounce(char *bounce)
{
	if (ft_atoi(bounce) <= 0)
		return (0);
	return (1);
}

void	ft_change_set(t_mini_rt *rt)
{
	rt->selec = __INT_MAX__;
	if (rt->info.new_speed)
	{
		if (ft_verif_speed_sensi(rt->info.new_speed))
			rt->info.speed = ft_atof(rt->info.new_speed);
		rt->info.new_speed = NULL;
	}
	if (rt->info.new_sensi)
	{
		if (ft_verif_speed_sensi(rt->info.new_sensi))
			rt->info.sensi = ft_atof(rt->info.new_sensi);
		rt->info.new_sensi = NULL;
	}
	if (rt->info.new_fov)
	{
		if (ft_verif_fov(rt->info.new_fov))
			rt->camera.fov = ft_atoi(rt->info.new_fov);
		rt->info.new_fov = NULL;
	}
	if (rt->info.new_bounce)
	{
		if (ft_verif_bounce(rt->info.new_bounce))
			rt->info.bounce = ft_atoi(rt->info.new_bounce);
		rt->info.new_bounce = NULL;
	}
}
