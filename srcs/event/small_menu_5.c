/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_menu_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:01:10 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/06 12:14:09 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	change_map(t_mini_rt *rt, int nb)
{
	rt->info.new_map = ft_strjoin("maps/json/",
			rt->info.maps_json[nb + rt->info.scroll]);
	if (!ft_strcmp(ft_recup_name(rt->info.map),
			rt->info.maps_json[nb + rt->info.scroll]))
		rt->info.new_map = NULL;
	rt->selec = __INT_MAX__;
}

void	ft_small_menu_5_2(t_mini_rt *rt)
{
	if (rt->selec == 27 + rt->size_object
		&& rt->info.nb_maps_json >= 8 + rt->info.scroll)
		change_map(rt, 7);
	else if (rt->selec == 28 + rt->size_object
		&& rt->info.nb_maps_json >= 9 + rt->info.scroll)
		change_map(rt, 8);
	else if (rt->selec == 29 + rt->size_object
		&& rt->info.nb_maps_json >= 10 + rt->info.scroll)
		change_map(rt, 9);
}

void	ft_small_menu_5(t_mini_rt *rt)
{
	if (rt->selec == 20 + rt->size_object
		&& rt->info.nb_maps_json >= 1 + rt->info.scroll)
		change_map(rt, 0);
	else if (rt->selec == 21 + rt->size_object
		&& rt->info.nb_maps_json >= 2 + rt->info.scroll)
		change_map(rt, 1);
	else if (rt->selec == 22 + rt->size_object
		&& rt->info.nb_maps_json >= 3 + rt->info.scroll)
		change_map(rt, 2);
	else if (rt->selec == 23 + rt->size_object
		&& rt->info.nb_maps_json >= 4 + rt->info.scroll)
		change_map(rt, 3);
	else if (rt->selec == 24 + rt->size_object
		&& rt->info.nb_maps_json >= 5 + rt->info.scroll)
		change_map(rt, 4);
	else if (rt->selec == 25 + rt->size_object
		&& rt->info.nb_maps_json >= 6 + rt->info.scroll)
		change_map(rt, 5);
	else if (rt->selec == 26 + rt->size_object
		&& rt->info.nb_maps_json >= 7 + rt->info.scroll)
		change_map(rt, 6);
	ft_small_menu_5_2(rt);
}
