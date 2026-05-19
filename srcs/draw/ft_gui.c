/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:30:45 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:42:03 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	ft_gui2(t_mini_rt *rt)
{
	mlx_string_put(rt->mlx, rt->win, 406, 19, 0xFFFFFF, "fov : ");
	mlx_string_put(rt->mlx, rt->win, 440, 20, 0xFFFFFF,
		ft_itoa_float(rt->camera.fov));
	mlx_string_put(rt->mlx, rt->win, 480, 19, 0xFFFFFF, "obj : ");
	mlx_string_put(rt->mlx, rt->win, 516, 20, 0xFFFFFF, ft_itoa_int(rt->selec));
	mlx_string_put(rt->mlx, rt->win, 600, 19, 0xFFFFFF, "exp : ");
	mlx_string_put(rt->mlx, rt->win, 636, 20, 0xFFFFFF,
		ft_itoa_float(rt->info.exposure));
	mlx_string_put(rt->mlx, rt->win, 680, 19, 0xFFFFFF, "sat : ");
	mlx_string_put(rt->mlx, rt->win, 716, 20, 0xFFFFFF,
		ft_itoa_float(rt->info.saturation));
	mlx_string_put(rt->mlx, rt->win, 760, 19, 0xFFFFFF, "wht : ");
	mlx_string_put(rt->mlx, rt->win, 796, 20, 0xFFFFFF,
		ft_itoa_float(rt->info.white));
}

void	ft_gui(t_mini_rt *rt, unsigned long elapsed)
{
	float	fps;

	fps = 1.0f / ((float)elapsed / 1000000.0f);
	mlx_set_font(rt->mlx, rt->win, "fixed");
	mlx_string_put(rt->mlx, rt->win, 10, 19, 0xFFFFFF, "fps : ");
	mlx_string_put(rt->mlx, rt->win, 48, 20, 0xFFFFFF, ft_itoa_float(fps));
	mlx_string_put(rt->mlx, rt->win, 78, 19, 0xFFFFFF, "x : ");
	mlx_string_put(rt->mlx, rt->win, 104, 20, 0xFFFFFF,
		ft_itoa_int(rt->camera.coord.x));
	mlx_string_put(rt->mlx, rt->win, 130, 19, 0xFFFFFF, "y : ");
	mlx_string_put(rt->mlx, rt->win, 156, 20, 0xFFFFFF,
		ft_itoa_int(rt->camera.coord.y));
	mlx_string_put(rt->mlx, rt->win, 182, 19, 0xFFFFFF, "z : ");
	mlx_string_put(rt->mlx, rt->win, 208, 20, 0xFFFFFF,
		ft_itoa_int(rt->camera.coord.z));
	mlx_string_put(rt->mlx, rt->win, 234, 19, 0xFFFFFF, "v(x) : ");
	mlx_string_put(rt->mlx, rt->win, 274, 20, 0xFFFFFF,
		ft_itoa_float(rt->camera.rot_x));
	mlx_string_put(rt->mlx, rt->win, 320, 19, 0xFFFFFF, "v(y) : ");
	mlx_string_put(rt->mlx, rt->win, 360, 20, 0xFFFFFF,
		ft_itoa_float(rt->camera.rot_y));
	ft_gui2(rt);
}
