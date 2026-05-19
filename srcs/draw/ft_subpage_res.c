/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subpage_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:18:31 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/27 14:23:02 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	ft_subpage_res_4(t_mini_rt *rt, float pos_x, float pos_y)
{
	if (rt->info.width == 426)
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 330 * pos_y, 0xFFFFFF,
			"426 x 240");
	else if (rt->info.new_width == 426)
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 330 * pos_y, 0x6534D5,
			"426 x 240");
	else
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 330 * pos_y, 0xDDDDDD,
			"426 x 240");
	if (rt->info.width == 256)
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 370 * pos_y, 0xFFFFFF,
			"256 x 140");
	else if (rt->info.new_width == 256)
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 370 * pos_y, 0x6534D5,
			"256 x 140");
	else
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 370 * pos_y, 0xDDDDDD,
			"256 x 140");
}

static void	ft_subpage_res_3(t_mini_rt *rt, float pos_x, float pos_y)
{
	if (rt->info.width == 960)
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 250 * pos_y, 0xFFFFFF,
			"960 x 480");
	else if (rt->info.new_width == 960)
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 250 * pos_y, 0x6534D5,
			"960 x 480");
	else
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 250 * pos_y, 0xDDDDDD,
			"960 x 480");
	if (rt->info.width == 640)
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 290 * pos_y, 0xFFFFFF,
			"640 x 350");
	else if (rt->info.new_width == 640)
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 290 * pos_y, 0x6534D5,
			"640 x 350");
	else
		mlx_string_put(rt->mlx, rt->win, 777 * pos_x, 290 * pos_y, 0xDDDDDD,
			"640 x 350");
	ft_subpage_res_4(rt, pos_x, pos_y);
}

static void	ft_subpage_res_2(t_mini_rt *rt, float pos_x, float pos_y)
{
	if (rt->info.width == 1600)
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 170 * pos_y, 0xFFFFFF,
			"1600 x 900");
	else if (rt->info.new_width == 1600)
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 170 * pos_y, 0x6534D5,
			"1600 x 900");
	else
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 170 * pos_y, 0xDDDDDD,
			"1600 x 900");
	if (rt->info.width == 1280)
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 210 * pos_y, 0xFFFFFF,
			"1280 x 720");
	else if (rt->info.new_width == 1280)
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 210 * pos_y, 0x6534D5,
			"1280 x 720");
	else
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 210 * pos_y, 0xDDDDDD,
			"1280 x 720");
	ft_subpage_res_3(rt, pos_x, pos_y);
}

void	ft_subpage_res(t_mini_rt *rt, float pos_x, float pos_y)
{
	mlx_string_put(rt->mlx, rt->win, 770 * pos_x, 47, 0xFFFFFF, "Resolution");
	if (rt->info.width == 2560)
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 90 * pos_y, 0xFFFFFF,
			"2560 x 1440");
	else if (rt->info.new_width == 2560)
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 90 * pos_y, 0x6534D5,
			"2560 x 1440");
	else
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 90 * pos_y, 0xDDDDDD,
			"2560 x 1440");
	if (rt->info.width == 1920)
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 130 * pos_y, 0xFFFFFF,
			"1920 x 1080");
	else if (rt->info.new_width == 1920)
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 130 * pos_y, 0x6534D5,
			"1920 x 1080");
	else
		mlx_string_put(rt->mlx, rt->win, 767 * pos_x, 130 * pos_y, 0xDDDDDD,
			"1920 x 1080");
	ft_subpage_res_2(rt, pos_x, pos_y);
}
