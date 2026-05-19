/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:24:52 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/11 13:39:16 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void	ft_change_input(t_mini_rt *rt, int keycode)
{
	if (rt->selec == 2 + rt->size_object + 31)
		rt->code_input.forward = keycode;
	else if (rt->selec == 3 + rt->size_object + 31)
		rt->code_input.left = keycode;
	else if (rt->selec == 6 + rt->size_object + 31)
		rt->code_input.backward = keycode;
	else if (rt->selec == 7 + rt->size_object + 31)
		rt->code_input.right = keycode;
	else if (rt->selec == 10 + rt->size_object + 31)
		rt->code_input.up = keycode;
	else if (rt->selec == 11 + rt->size_object + 31)
		rt->code_input.down = keycode;
	else if (rt->selec == 14 + rt->size_object + 31)
		rt->code_input.rot_on_off = keycode;
	else if (rt->selec == 15 + rt->size_object + 31)
		rt->code_input.rot_obj = keycode;
	else if (rt->selec == 18 + rt->size_object + 31)
		rt->code_input.menu = keycode;
	else if (rt->selec == 19 + rt->size_object + 31)
		rt->code_input.blur = keycode;
}

int	ft_press_control(int keycode, t_mini_rt *rt)
{
	if (keycode == rt->code_input.quit)
		ft_esc(rt);
	if (rt->selec != __INT_MAX__)
	{
		ft_change_input(rt, keycode);
		rt->selec = __INT_MAX__;
	}
	else if (keycode == rt->code_input.menu)
		ft_enter_menu(rt);
	return (0);
}
