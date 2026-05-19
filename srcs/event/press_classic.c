/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_classic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:37:08 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 10:26:04 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	ft_blur(t_mini_rt *rt)
{
	if (rt->blur_done == 0)
		rt->blur_done = 1;
	else if (rt->blur_done == 3)
	{
		rt->blur_done = 0;
		rt->nb_img = 0;
	}
}

static void	ft_switch(t_mini_rt *rt, unsigned char *var, int mode)
{
	if (*var == 0)
	{
		if (mode == 2)
			rt->info.bounce = 1;
		*var = 1;
	}
	else
	{
		if (mode == 2)
			rt->info.bounce = 10;
		*var = 0;
		if (mode == 1)
			rt->nb_img = 0;
	}
	if (mode == 0)
		rt->nb_img = 0;
}

int	ft_press_classic_2(int keycode, t_mini_rt *rt)
{
	if (keycode == rt->code_input.bvh && rt->page == 0)
		ft_switch(rt, &rt->bvh_on, 0);
	else if (keycode == rt->code_input.normal && rt->page == 0)
		ft_switch(rt, &rt->normal_on, 2);
	else if (keycode == rt->code_input.opti && rt->page == 0)
		ft_switch(rt, &rt->opti_on, 1);
	else if (keycode == 65430 && rt->page == 0)
		ft_switch(rt, &rt->tone_on, 1);
	else if (keycode == 65480 && rt->page == 0)
		rt->info.exposure -= 0.01f;
	else if (keycode == 65481 && rt->page == 0)
		rt->info.exposure += 0.01f;
	else if (keycode == 65478 && rt->page == 0)
		rt->info.saturation -= 0.01f;
	else if (keycode == 65479 && rt->page == 0)
		rt->info.saturation += 0.01f;
	else if (keycode == 65476 && rt->page == 0)
		rt->info.white -= 0.1f;
	else if (keycode == 65477 && rt->page == 0)
		rt->info.white += 0.1f;
	return (0);
}

int	ft_press_classic(int keycode, t_mini_rt *rt)
{
	if (keycode == rt->code_input.quit)
		ft_esc(rt);
	else if (keycode == rt->code_input.rot_on_off && rt->page == 0)
		ft_on_off_rot(rt);
	else if (keycode == rt->code_input.rot_obj && rt->page == 0)
		ft_on_off_rot_obj(rt);
	else if (keycode == rt->code_input.forward && rt->page == 0)
		rt->input.forward = 1;
	else if (keycode == rt->code_input.left && rt->page == 0)
		rt->input.left = 1;
	else if (keycode == rt->code_input.backward && rt->page == 0)
		rt->input.backward = 1;
	else if (keycode == rt->code_input.right && rt->page == 0)
		rt->input.right = 1;
	else if (keycode == rt->code_input.up && rt->page == 0)
		rt->input.up = 1;
	else if (keycode == rt->code_input.down && rt->page == 0)
		rt->input.down = 1;
	else if (keycode == rt->code_input.blur && rt->page == 0)
		ft_blur(rt);
	ft_press_classic_2(keycode, rt);
	return (0);
}
