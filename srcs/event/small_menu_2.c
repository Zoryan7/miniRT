/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_menu_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:15:42 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/11 13:39:48 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	ft_small_menu_2_2(t_mini_rt *rt)
{
	if (rt->selec == 15 + rt->size_object && rt->page != 1)
	{
		rt->page = 1;
		rt->nb_img = 0;
		rt->selec = __INT_MAX__;
	}
	else if (rt->selec == 16 + rt->size_object)
	{
		ft_close(rt);
		rt->selec = __INT_MAX__;
	}
	else if (rt->selec == 18 + rt->size_object)
	{
		rt->selec = __INT_MAX__;
		if (rt->page == 5)
			rt->page = 4;
	}
	else if (rt->selec == 19 + rt->size_object)
	{
		rt->selec = __INT_MAX__;
		if (rt->page == 4)
			rt->page = 5;
	}
}

static void	ft_small_menu_2_3(t_mini_rt *rt)
{
	if (rt->selec == 13 + rt->size_object)
	{
		if (rt->info.new_width || rt->info.new_map)
			ft_restart(rt);
	}
	else if (rt->selec == 2 + rt->size_object)
	{
		rt->selec = __INT_MAX__;
		rt->info.scroll = 0;
		if (rt->page == 3)
		{
			rt->page = 2;
			rt->object[30].transparency = 1;
		}
		else
		{
			rt->page = 3;
			rt->object[30].transparency = 0.9;
		}
	}
}

static void	ft_small_menu_2_4(t_mini_rt *rt)
{
	if (rt->selec == 4 + rt->size_object)
	{
		if (rt->page == 4 || rt->page == 5)
		{
			rt->object[30].transparency = 1;
			rt->page = 2;
		}
		else
		{
			rt->page = 4;
			rt->object[30].transparency = 0.9;
		}
		rt->info.scroll = 0;
		rt->selec = __INT_MAX__;
	}
}

void	ft_small_menu_2(t_mini_rt *rt)
{
	ft_small_menu_2_2(rt);
	ft_small_menu_2_3(rt);
	ft_small_menu_2_4(rt);
	if (rt->page == 3)
		ft_small_menu_3(rt);
	if (rt->page == 4)
		ft_small_menu_4(rt);
	if (rt->page == 5)
		ft_small_menu_5(rt);
}
