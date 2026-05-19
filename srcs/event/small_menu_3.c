/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_menu_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:00:37 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/06 12:10:49 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	change_res(t_mini_rt *rt, int new_width, int new_height)
{
	rt->info.new_width = new_width;
	rt->info.new_height = new_height;
	if (rt->info.width == new_width)
	{
		rt->info.new_width = 0;
		rt->info.new_height = 0;
	}
	rt->selec = __INT_MAX__;
}

void	ft_small_menu_3(t_mini_rt *rt)
{
	if (rt->selec == 20 + rt->size_object)
		change_res(rt, 2560, 1440);
	else if (rt->selec == 21 + rt->size_object)
		change_res(rt, 1920, 1080);
	else if (rt->selec == 22 + rt->size_object)
		change_res(rt, 1600, 900);
	else if (rt->selec == 23 + rt->size_object)
		change_res(rt, 1280, 720);
	else if (rt->selec == 24 + rt->size_object)
		change_res(rt, 960, 480);
	else if (rt->selec == 25 + rt->size_object)
		change_res(rt, 640, 350);
	else if (rt->selec == 26 + rt->size_object)
		change_res(rt, 426, 240);
	else if (rt->selec == 27 + rt->size_object)
		change_res(rt, 256, 140);
}
