/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:35:27 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/06 11:35:49 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	ft_change_speed(t_mini_rt *rt, int keycode)
{
	char	*touch;
	char	dst[2];

	dst[1] = 0;
	touch = ft_atoa(keycode, dst, &rt->keycode_dict);
	if (ft_strisdigit(touch) || !ft_strcmp(touch, ",") || !ft_strcmp(touch,
			"."))
	{
		if (!ft_strcmp(touch, ","))
			rt->info.new_speed = ft_strjoin(rt->info.new_speed, ".");
		else
			rt->info.new_speed = ft_strjoin_ff(rt->info.new_speed, touch);
	}
}

static void	ft_change_sensi(t_mini_rt *rt, int keycode)
{
	char	*touch;
	char	dst[2];

	dst[1] = 0;
	touch = ft_atoa(keycode, dst, &rt->keycode_dict);
	if (ft_strisdigit(touch) || !ft_strcmp(touch, ",") || !ft_strcmp(touch,
			"."))
	{
		if (!ft_strcmp(touch, ","))
			rt->info.new_sensi = ft_strjoin(rt->info.new_sensi, ".");
		else
			rt->info.new_sensi = ft_strjoin_ff(rt->info.new_sensi, touch);
	}
}

static void	ft_change_fov(t_mini_rt *rt, int keycode)
{
	char	*touch;
	char	dst[2];

	dst[1] = 0;
	touch = ft_atoa(keycode, dst, &rt->keycode_dict);
	if (ft_strisdigit(touch))
		rt->info.new_fov = ft_strjoin(rt->info.new_fov, touch);
}

static void	ft_change_bounce(t_mini_rt *rt, int keycode)
{
	char	*touch;
	char	dst[2];

	dst[1] = 0;
	touch = ft_atoa(keycode, dst, &rt->keycode_dict);
	if (ft_strisdigit(touch))
		rt->info.new_bounce = ft_strjoin(rt->info.new_bounce, touch);
}

void	ft_change_info(t_mini_rt *rt, int keycode)
{
	if (rt->selec == 7 + rt->size_object)
		ft_change_speed(rt, keycode);
	else if (rt->selec == 8 + rt->size_object)
		ft_change_sensi(rt, keycode);
	else if (rt->selec == 11 + rt->size_object)
		ft_change_fov(rt, keycode);
	else if (rt->selec == 12 + rt->size_object)
		ft_change_bounce(rt, keycode);
}
