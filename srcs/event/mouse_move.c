/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:10:27 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/10 10:45:16 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	ft_rot_cam(t_mini_rt *rt, float rot_x, float rot_y)
{
	if (rt->camera.rot_x < -80)
		rt->camera.rot_x = -80;
	if (rt->camera.rot_x > 80)
		rt->camera.rot_x = 80;
	rt->camera.rot_y += rt->info.sensi * rot_x;
	rt->camera.rot_x += rt->info.sensi * rot_y;
}

static void	ft_rot_obj(t_mini_rt *rt, float rot_x, float rot_y)
{
	if (rt->object[rt->selec].rot_x < -80)
		rt->object[rt->selec].rot_x = -80;
	if (rt->object[rt->selec].rot_x > 80)
		rt->object[rt->selec].rot_x = 80;
	rt->object[rt->selec].rot_y += rt->info.sensi * rot_x;
	rt->object[rt->selec].rot_x += rt->info.sensi * rot_y;
}

static void	ft_mouse_move_2(t_mini_rt *rt, t_mouse_move_info *info, int *old_x,
		int *old_y)
{
	if (*old_x != info->x - rt->info.width_mid || *old_y != info->y
		- rt->info.height_mid)
		rt->move_on = 1;
	if (info->x >= rt->info.width_mid + (rt->info.width / 8)
		|| info->x < rt->info.width_mid - (rt->info.width / 8)
		|| info->y >= rt->info.height_mid + (rt->info.height / 8)
		|| info->y < rt->info.height_mid - (rt->info.height / 8))
	{
		*old_x -= info->x - rt->info.width_mid;
		*old_y -= info->y - rt->info.height_mid;
		mlx_mouse_move(rt->mlx, rt->win, rt->info.width_mid,
			rt->info.height_mid);
	}
	else
	{
		info->rot_x = (float)(info->x - rt->info.width_mid - *old_x);
		info->rot_y = (float)(info->y - rt->info.height_mid - *old_y);
		if (rt->selec == __INT_MAX__ || rt->rot_obj == 0)
			ft_rot_cam(rt, info->rot_x, info->rot_y);
		else
			ft_rot_obj(rt, info->rot_x, info->rot_y);
		*old_x = info->x - rt->info.width_mid;
		*old_y = info->y - rt->info.height_mid;
	}
}

int	ft_mouse_move(t_mini_rt *rt)
{
	static int			old_x = -1;
	static int			old_y = -1;
	t_mouse_move_info	info;

	rt->move_on = 0;
	mlx_mouse_get_pos(rt->mlx, rt->win, &info.x, &info.y);
	if (old_x == -1)
	{
		mlx_mouse_move(rt->mlx, rt->win, rt->info.width_mid,
			rt->info.height_mid);
		old_x = info.x - rt->info.width_mid;
		old_y = info.y - rt->info.height_mid;
	}
	if (rt->rot_on == 1 && rt->page == 0)
		ft_mouse_move_2(rt, &info, &old_x, &old_y);
	return (0);
}
