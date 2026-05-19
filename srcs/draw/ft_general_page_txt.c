/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_page_txt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:03:44 by etessoer          #+#    #+#             */
/*   Updated: 2026/05/18 14:21:32 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

char	*ft_recup_name(char *map)
{
	if (!map)
		return (NULL);
	if (!ft_strncmp(map, "maps/rt/", 8))
		return (&map[8]);
	else if (!ft_strncmp(map, "maps/json/", 10))
		return (&map[10]);
	return (NULL);
}

static void	ft_general_page_4(t_mini_rt *rt, float pos_x, float pos_y)
{
	mlx_string_put(rt->mlx, rt->win, 615 * pos_x, 438 * pos_y, 0xFFFFFF,
		"Apply");
	mlx_string_put(rt->mlx, rt->win, 122 * pos_x, 60 * pos_y, 0xFFFFFF,
		"General");
	mlx_string_put(rt->mlx, rt->win, 122 * pos_x, 94 * pos_y, 0xDDDDDD,
		"Control");
	mlx_string_put(rt->mlx, rt->win, 138 * pos_x, 128 * pos_y, 0xDDDDDD,
		"Exit");
}

static void	ft_general_page_3(t_mini_rt *rt, char *name, float pos_x,
	float pos_y)
{
	free(name);
	if (rt->selec == 8 + rt->size_object)
		name = ft_strdup(rt->info.new_sensi);
	else
		name = ft_itoa_float(rt->info.sensi);
	if (!name)
		name = ft_strdup(" ");
	mlx_string_put(rt->mlx, rt->win, (640 - (ft_strlen(name) * 4)) * pos_x, 302
		* pos_y, 0xFFFFFF, name);
	mlx_string_put(rt->mlx, rt->win, 505 * pos_x, 378 * pos_y, 0xFFFFFF,
		"Bounce");
	if (rt->selec == 12 + rt->size_object)
		name = ft_strdup(rt->info.new_bounce);
	else
		name = ft_itoa(rt->info.bounce);
	if (!name)
		name = ft_strdup(" ");
	mlx_string_put(rt->mlx, rt->win, (640 - (ft_strlen(name) * 4)) * pos_x, 378
		* pos_y, 0xFFFFFF, name);
	free(name);
	if (rt->page == 3)
		ft_subpage_res(rt, pos_x, pos_y);
	if (rt->page == 4 || rt->page == 5)
		ft_subpage_map(rt, pos_x, pos_y);
	ft_general_page_4(rt, pos_x, pos_y);
}

static void	ft_general_page_2(t_mini_rt *rt, char *name, float pos_x,
		float pos_y)
{
	free(name);
	if (rt->selec == 7 + rt->size_object)
		name = ft_strdup(rt->info.new_speed);
	else
		name = ft_strdup(ft_itoa_float(rt->info.speed));
	if (!name)
		name = ft_strdup(" ");
	mlx_string_put(rt->mlx, rt->win, (420 - (ft_strlen(name) * 5)) * pos_x, 302
		* pos_y, 0xFFFFFF, name);
	free(name);
	mlx_string_put(rt->mlx, rt->win, 280 * pos_x, 378 * pos_y, 0xFFFFFF, "FOV");
	if (rt->selec == 11 + rt->size_object)
		name = ft_strdup(rt->info.new_fov);
	else
		name = ft_itoa(rt->camera.fov);
	if (!name)
		name = ft_strdup(" ");
	mlx_string_put(rt->mlx, rt->win, (420 - (ft_strlen(name) * 5)) * pos_x, 378
		* pos_y, 0xFFFFFF, name);
	mlx_string_put(rt->mlx, rt->win, 505 * pos_x, 302 * pos_y, 0xFFFFFF,
		"Sensi");
	ft_general_page_3(rt, name, pos_x, pos_y);
}

void	ft_general_page(t_mini_rt *rt)
{
	char	*name;
	float	pos_x;
	float	pos_y;

	pos_x = (float)rt->info.width / 960.0f;
	pos_y = (float)rt->info.height / 480.0f;
	mlx_set_font(rt->mlx, rt->win, "10x20");
	mlx_string_put(rt->mlx, rt->win, 270 * pos_x, 60 * pos_y, 0xFFFFFF,
		"General");
	mlx_string_put(rt->mlx, rt->win, 280 * pos_x, 155 * pos_y, 0xFFFFFF,
		"Resolution");
	name = ft_strjoin_df(ft_strjoin_ff(ft_strjoin_ff(ft_itoa(rt->info.width),
					" "), "x"), ft_strjoin_fs(" ", ft_itoa(rt->info.height)));
	mlx_string_put(rt->mlx, rt->win, (500 - (ft_strlen(name) * 5)) * pos_x, 155
		* pos_y, 0xFFFFFF, name);
	mlx_string_put(rt->mlx, rt->win, 280 * pos_x, 230 * pos_y, 0xFFFFFF,
		"Maps");
	free(name);
	name = ft_clamp_name(ft_recup_name(rt->info.map), 10);
	mlx_string_put(rt->mlx, rt->win, (500 - (ft_strlen(name) * 5)) * pos_x, 230
		* pos_y, 0xFFFFFF, name);
	mlx_string_put(rt->mlx, rt->win, 280 * pos_x, 302 * pos_y, 0xFFFFFF,
		"Speed");
	ft_general_page_2(rt, name, pos_x, pos_y);
}
