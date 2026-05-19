/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:08:52 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/06 11:39:58 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	ft_press(int keycode, t_mini_rt *rt)
{
	if (rt->page == 0)
		return (ft_press_classic(keycode, rt));
	else if (rt->page == 1)
		return (ft_press_control(keycode, rt));
	else if (rt->page == 2 || rt->page == 3 || rt->page == 4 || rt->page == 5)
		return (ft_press_general(keycode, rt));
	return (0);
}
