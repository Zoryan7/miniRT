/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_classic_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:38:46 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/10 10:34:38 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void	ft_esc(t_mini_rt *rt)
{
	if (rt->selec == __INT_MAX__ && rt->page == 0)
		ft_close(rt);
	else if (rt->selec != __INT_MAX__)
	{
		rt->selec = __INT_MAX__;
		ft_change_set(rt);
		if (rt->page == 3 || rt->page == 4 || rt->page == 5)
			rt->page = 2;
		if (rt->page == 0)
			rt->rot_obj = 0;
	}
	else
	{
		rt->rot_on = 1;
		rt->page = 0;
		mlx_mouse_hide(rt->mlx, rt->win);
	}
}

void	ft_enter_menu(t_mini_rt *rt)
{
	if (rt->page == 0)
	{
		rt->cur_task = 0;
		rt->done_task = 0;
		rt->page = 2;
		rt->nb_img = 0;
		rt->rot_on = 0;
		mlx_mouse_show(rt->mlx, rt->win);
	}
	else
	{
		rt->rot_on = 1;
		rt->nb_img = 0;
		rt->page = 0;
		mlx_mouse_hide(rt->mlx, rt->win);
	}
}

void	ft_on_off_rot(t_mini_rt *rt)
{
	if (rt->rot_on == 0)
	{
		mlx_mouse_hide(rt->mlx, rt->win);
		rt->rot_on = 1;
	}
	else
	{
		mlx_mouse_show(rt->mlx, rt->win);
		rt->rot_on = 0;
	}
}

void	ft_on_off_rot_obj(t_mini_rt *rt)
{
	if (rt->rot_obj == 0 && rt->selec != __INT_MAX__)
		rt->rot_obj = 1;
	else if (rt->selec != __INT_MAX__)
		rt->rot_obj = 0;
}
