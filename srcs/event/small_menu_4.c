/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_menu_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:00:52 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/06 12:11:44 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	change_map(t_mini_rt *rt, int nb)
{
	rt->info.new_map = ft_strjoin("maps/rt/",
			rt->info.maps_rt[nb + rt->info.scroll]);
	if (!ft_strcmp(ft_recup_name(rt->info.map),
			rt->info.maps_rt[nb + rt->info.scroll]))
		rt->info.new_map = NULL;
	rt->selec = __INT_MAX__;
}

static void	ft_small_menu_4_2(t_mini_rt *rt)
{
	if (rt->selec == 27 + rt->size_object
		&& rt->info.nb_maps_rt >= 8 + rt->info.scroll)
		change_map(rt, 7);
	else if (rt->selec == 28 + rt->size_object
		&& rt->info.nb_maps_rt >= 9 + rt->info.scroll)
		change_map(rt, 8);
	else if (rt->selec == 29 + rt->size_object
		&& rt->info.nb_maps_rt >= 10 + rt->info.scroll)
		change_map(rt, 9);
}

void	ft_small_menu_4(t_mini_rt *rt)
{
	if (rt->selec == 20 + rt->size_object
		&& rt->info.nb_maps_rt >= 1 + rt->info.scroll)
		change_map(rt, 0);
	else if (rt->selec == 21 + rt->size_object
		&& rt->info.nb_maps_rt >= 2 + rt->info.scroll)
		change_map(rt, 1);
	else if (rt->selec == 22 + rt->size_object
		&& rt->info.nb_maps_rt >= 3 + rt->info.scroll)
		change_map(rt, 2);
	else if (rt->selec == 23 + rt->size_object
		&& rt->info.nb_maps_rt >= 4 + rt->info.scroll)
		change_map(rt, 3);
	else if (rt->selec == 24 + rt->size_object
		&& rt->info.nb_maps_rt >= 5 + rt->info.scroll)
		change_map(rt, 4);
	else if (rt->selec == 25 + rt->size_object
		&& rt->info.nb_maps_rt >= 6 + rt->info.scroll)
		change_map(rt, 5);
	else if (rt->selec == 26 + rt->size_object
		&& rt->info.nb_maps_rt >= 7 + rt->info.scroll)
		change_map(rt, 6);
	ft_small_menu_4_2(rt);
}
