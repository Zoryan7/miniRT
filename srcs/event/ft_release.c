/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_release.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:08:36 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/16 17:16:22 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	ft_release(int keycode, t_mini_rt *rt)
{
	if (keycode == rt->code_input.forward && rt->page == 0)
		rt->input.forward = 0;
	else if (keycode == rt->code_input.left && rt->page == 0)
		rt->input.left = 0;
	else if (keycode == rt->code_input.backward && rt->page == 0)
		rt->input.backward = 0;
	else if (keycode == rt->code_input.right && rt->page == 0)
		rt->input.right = 0;
	else if (keycode == rt->code_input.up && rt->page == 0)
		rt->input.up = 0;
	else if (keycode == rt->code_input.down && rt->page == 0)
		rt->input.down = 0;
	return (0);
}
