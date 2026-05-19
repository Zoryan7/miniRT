/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:50 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/08 17:44:14 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void	ft_select(t_mini_rt *rt)
{
	t_vec2	inter;
	t_ray	ray;
	float	dist_obj;
	int		ind_obj;
	int		i;

	i = 0;
	dist_obj = INFINITY;
	ind_obj = __INT_MAX__;
	ray.origin = rt->camera.coord;
	ray.direction = rt->camera.forward;
	ray.r_direction = ft_vec_divide_vec((t_vec){{1.0f, 1.0f, 1.0f}},
			ray.direction);
	while (i < rt->size_object)
	{
		inter = ft_choose_intersect(rt->object[i], ray);
		if (inter.x < dist_obj && inter.y > 0)
		{
			dist_obj = inter.x;
			ind_obj = i;
		}
		i++;
	}
	rt->selec = ind_obj;
}

int	ft_is_in_subpage(t_mini_rt *rt, int x, int y)
{
	float	pos_x;
	float	pos_y;

	pos_x = (float)rt->info.width / 960.0f;
	pos_y = (float)rt->info.height / 480.0f;
	if (x > 750 * pos_x && x < 900 * pos_x && y > 30 * pos_y && y < 450 * pos_y)
		return (1);
	return (0);
}

static void	scroll(t_mini_rt *rt, int keycode, int x, int y)
{
	if (keycode == 4 && (rt->page == 4 || rt->page == 5)
		&& ft_is_in_subpage(rt, x, y))
	{
		if (rt->info.scroll != 0)
			rt->info.scroll -= 1;
	}
	if (keycode == 5 && rt->page == 4 && ft_is_in_subpage(rt, x, y))
	{
		if (rt->info.scroll < rt->info.nb_maps_rt - 1)
			rt->info.scroll += 1;
	}
	if (keycode == 5 && rt->page == 5 && ft_is_in_subpage(rt, x, y))
	{
		if (rt->info.scroll < rt->info.nb_maps_json - 1)
			rt->info.scroll += 1;
	}
}

int	ft_mouse_hook(int keycode, int x, int y, t_mini_rt *rt)
{
	if (keycode == 1 && rt->page == 0)
		ft_select(rt);
	if (keycode == 1 && rt->page == 1)
		ft_select_control(rt, x, y);
	if (keycode == 1 && (rt->page == 2 || rt->page == 3
			|| rt->page == 4 || rt->page == 5))
		ft_select_general(rt, x, y);
	scroll(rt, keycode, x, y);
	if (keycode == 4 && rt->page == 0)
	{
		rt->nb_img = 0;
		if (rt->camera.fov > 30)
			rt->camera.fov -= 1;
	}
	if (keycode == 5 && rt->page == 0)
	{
		rt->nb_img = 0;
		if (rt->camera.fov < 179)
			rt->camera.fov += 1;
	}
	return (0);
}
