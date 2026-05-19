/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:51:33 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/11 13:39:16 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-definition"

static int	ft_mlx_mouse_hook(keycode, x, y, param)
	int	keycode;
	int	x;
	int	y;
	void	*param;
{
	return (ft_mouse_hook(keycode, x, y, (t_mini_rt *)param));
}

static int	ft_mlx_press_hook(keycode, param)
	int	keycode;
	void	*param;
{
	return (ft_press(keycode, (t_mini_rt *)param));
}

static int	ft_mlx_release_hook(keycode, param)
	int	keycode;
	void	*param;
{
	return (ft_release(keycode, (t_mini_rt *)param));
}

static int	ft_mlx_close_hook(param)
	void	*param;
{
	return (ft_close((t_mini_rt *)param));
}

#pragma GCC diagnostic pop

static void	ft_restart_2(t_mini_rt *rt, int file_t, int res_change, char **av)
{
	if (rt->info.new_map)
	{
		rt->info.map = rt->info.new_map;
		rt->info.new_map = NULL;
	}
	file_t = ft_verif_file_name(av[1]);
	if (file_t == -1)
		ft_close(rt);
	if (!ft_parsing_file(av[1], rt, file_t))
		ft_close(rt);
	if (rt->info.new_width)
	{
		rt->info.width = rt->info.new_width;
		rt->info.new_width = 0;
		rt->info.height = rt->info.new_height;
		rt->info.new_height = 0;
		res_change = 1;
	}
	if (res_change)
	{
		rt->info.width_mid = rt->info.width * 0.5;
		rt->info.height_mid = rt->info.height * 0.5;
		ft_resize_task_arrays(rt);
	}
}

void	ft_restart(t_mini_rt *rt)
{
	char	**av;
	int		file_t;
	int		res_change;

	res_change = 0;
	av = (char *[2]){"./piiiiin", rt->info.map};
	file_t = 0;
	ft_restart_2(rt, file_t, res_change, av);
	rt->rot_on = 1;
	rt->nb_img = 0;
	rt->page = 0;
	rt->selec = __INT_MAX__;
	mlx_mouse_hide(rt->mlx, rt->win);
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_destroy_image(rt->mlx, rt->img.img);
	rt->img.img = mlx_new_image(rt->mlx, rt->info.width, rt->info.height);
	rt->img.addr = mlx_get_data_addr(rt->img.img, &rt->img.bits_per_pixel,
			&rt->img.line_length, &rt->img.endian);
	rt->win = mlx_new_window(rt->mlx, rt->info.width,
			rt->info.height, "Mini RT");
	mlx_mouse_hook(rt->win, ft_mlx_mouse_hook, rt);
	mlx_hook(rt->win, 2, 1L << 0, ft_mlx_press_hook, rt);
	mlx_hook(rt->win, 3, 1L << 1, ft_mlx_release_hook, rt);
	mlx_hook(rt->win, 33, 1L << 17, ft_mlx_close_hook, rt);
	mlx_mouse_hide(rt->mlx, rt->win);
}

static void	ft_calcul_ray(t_mini_rt *rt, t_ray *ray, int x, int y)
{
	t_vec			target;

	target = rt->camera.view_origin;
	target.v = target.v + rt->camera.delta_u.v * (float)x;
	target.v = target.v + rt->camera.delta_v.v * (float)y;
	ray->origin = rt->camera.coord;
	ray->direction = ft_vec_normalize(ft_vec_sub(target, ray->origin));
	ray->r_direction = ft_vec_divide_vec((t_vec){{1.0f, 1.0f, 1.0f}},
			ray->direction);
}

static void	ft_init_info(t_mini_rt *rt, t_select_info *info)
{
	info->i = rt->size_object;
	info->dist_obj = INFINITY;
	info->ind_obj = __INT_MAX__;
}

void	ft_select_general(t_mini_rt *rt, int x, int y)
{
	t_vec2			inter;
	t_ray			ray;
	t_select_info	info;

	ft_init_info(rt, &info);
	ft_calcul_ray(rt, &ray, x, y);
	while (info.i < rt->size_object + 31)
	{
		if (info.i == rt->size_object || info.i == 17 + rt->size_object
			|| info.i == 30 + rt->size_object)
		{
			info.i++;
			continue ;
		}
		inter = ft_intersect_r_box(ray, rt->object[info.i]);
		if (inter.x < info.dist_obj && inter.y > 0)
		{
			info.dist_obj = inter.x;
			info.ind_obj = info.i;
		}
		info.i++;
	}
	rt->selec = info.ind_obj;
	ft_small_menu_2(rt);
}
