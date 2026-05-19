/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subpage_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:19:27 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/27 14:21:02 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	ft_subpage_map_json(t_mini_rt *rt, float pos_x, float pos_y)
{
	int	i;

	if (rt->page == 4)
	{
		i = rt->info.scroll;
		while (i < rt->info.nb_maps_rt && i < 10 + rt->info.scroll)
		{
			if (!ft_strcmp(rt->info.maps_rt[i], ft_recup_name(rt->info.map)))
				mlx_string_put(rt->mlx, rt->win, 767 * pos_x, (90 + (i
							- rt->info.scroll) * 40) * pos_y, 0xFFFFFF,
					ft_clamp_name(rt->info.maps_rt[i], 8));
			else if (!ft_strcmp(rt->info.maps_rt[i],
					ft_recup_name(rt->info.new_map)))
				mlx_string_put(rt->mlx, rt->win, 767 * pos_x, (90 + (i
							- rt->info.scroll) * 40) * pos_y, 0x6534D5,
					ft_clamp_name(rt->info.maps_rt[i], 8));
			else
				mlx_string_put(rt->mlx, rt->win, 767 * pos_x, (90 + (i
							- rt->info.scroll) * 40) * pos_y, 0xDDDDDD,
					ft_clamp_name(rt->info.maps_rt[i], 8));
			i++;
		}
	}
}

static void	ft_subpage_map_rt(t_mini_rt *rt, float pos_x, float pos_y)
{
	int	i;

	if (rt->page == 5)
	{
		i = 0;
		while (i < rt->info.nb_maps_json && i < 10)
		{
			if (!ft_strcmp(rt->info.maps_json[i], rt->info.map))
				mlx_string_put(rt->mlx, rt->win, 767 * pos_x, (90 + (i
							- rt->info.scroll) * 40) * pos_y, 0xFFFFFF,
					ft_clamp_name(rt->info.maps_json[i], 8));
			else if (!ft_strcmp(rt->info.maps_json[i],
					ft_recup_name(rt->info.new_map)))
				mlx_string_put(rt->mlx, rt->win, 767 * pos_x, (90 + (i
							- rt->info.scroll) * 40) * pos_y, 0x6534D5,
					ft_clamp_name(rt->info.maps_json[i], 8));
			else
				mlx_string_put(rt->mlx, rt->win, 767 * pos_x, (90 + (i
							- rt->info.scroll) * 40) * pos_y, 0xDDDDDD,
					ft_clamp_name(rt->info.maps_json[i], 8));
			i++;
		}
	}
}

void	ft_subpage_map(t_mini_rt *rt, float pos_x, float pos_y)
{
	if (rt->page == 4)
		mlx_string_put(rt->mlx, rt->win, 780 * pos_x, 47 * pos_y, 0xFFFFFF,
			"rt");
	else
		mlx_string_put(rt->mlx, rt->win, 780 * pos_x, 47 * pos_y, 0xDDDDDD,
			"rt");
	if (rt->page == 5)
		mlx_string_put(rt->mlx, rt->win, 830 * pos_x, 47 * pos_y, 0xFFFFFF,
			"json");
	else
		mlx_string_put(rt->mlx, rt->win, 830 * pos_x, 47 * pos_y, 0xDDDDDD,
			"json");
	ft_subpage_map_rt(rt, pos_x, pos_y);
	ft_subpage_map_json(rt, pos_x, pos_y);
}
