/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:33:38 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 11:53:17 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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

static int	ft_mlx_render_hook(param)
	void	*param;
{
	return (ft_render((t_mini_rt *)param));
}

#pragma GCC diagnostic pop

int	ft_create_images(t_mini_rt *rt)
{
	int	i;

	i = 0;
	while (i < rt->size_texture)
	{
		rt->texture[i].img.img = mlx_xpm_file_to_image(rt->mlx,
				rt->texture[i].name, &rt->texture[i].width,
				&rt->texture[i].height);
		if (!rt->texture[i].img.img)
			return (1);
		rt->texture[i].img.addr = mlx_get_data_addr(rt->texture[i].img.img,
				&rt->texture[i].img.bits_per_pixel,
				&rt->texture[i].img.line_length, &rt->texture[i].img.endian);
		if (!rt->texture[i].img.addr)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mini_rt	*rt;

	rt = ft_parsing(ac, av);
	if (!rt)
		return (ft_free_gc(), 1);
	rt->mlx = mlx_init();
	if (ft_create_images(rt))
		return (ft_putstr_fd("texture Error\n", 2), ft_free_gc(), 1);
	rt->img.img = mlx_new_image(rt->mlx, rt->info.width, rt->info.height);
	rt->img.addr = mlx_get_data_addr(rt->img.img, &rt->img.bits_per_pixel,
			&rt->img.line_length, &rt->img.endian);
	rt->win = mlx_new_window(rt->mlx, rt->info.width, rt->info.height,
			"Mini RT");
	mlx_mouse_hook(rt->win, ft_mlx_mouse_hook, rt);
	mlx_hook(rt->win, 2, 1L << 0, ft_mlx_press_hook, rt);
	mlx_hook(rt->win, 3, 1L << 1, ft_mlx_release_hook, rt);
	mlx_hook(rt->win, 33, 1L << 17, ft_mlx_close_hook, rt);
	mlx_mouse_hide(rt->mlx, rt->win);
	ft_init_task(rt);
	ft_init_thread(rt);
	mlx_loop_hook(rt->mlx, ft_mlx_render_hook, rt);
	mlx_loop(rt->mlx);
	ft_free_gc();
	return (0);
}
