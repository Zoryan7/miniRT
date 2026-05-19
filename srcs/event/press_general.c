/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:24:40 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/06 11:40:42 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	ft_press_general(int keycode, t_mini_rt *rt)
{
	if (keycode == rt->code_input.quit)
		ft_esc(rt);
	if (keycode == 65293)
		ft_change_set(rt);
	if (rt->selec != __INT_MAX__)
		ft_change_info(rt, keycode);
	else if (keycode == rt->code_input.menu)
		ft_enter_menu(rt);
	return (0);
}
