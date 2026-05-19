/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 06:16:55 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 06:23:45 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	ft_init_all_t(t_vec2 t, t_vec2 t_bouchon, t_vec *all_t)
{
	all_t->v[0] = t.x;
	all_t->v[1] = t.y;
	all_t->v[2] = t_bouchon.x;
	all_t->v[3] = t_bouchon.y;
}

void	ft_init_min2_i(float *min1, float *min2, int *i)
{
	*min1 = -1;
	*min2 = -1;
	*i = 0;
}
