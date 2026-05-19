/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crosshair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 11:41:03 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/13 15:37:48 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_crosshair(t_mini_rt *rt)
{
	if (rt->page == 0 && rt->selec == __INT_MAX__ && rt->rot_on == 1)
		mlx_string_put(rt->mlx, rt->win, rt->info.width_mid, rt->info.height_mid
			+ 5, 0xFFFFFF, "+");
}
