/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:44:45 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 05:39:48 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float	*ft_gauss(void)
{
	int		radius;
	int		dx;
	float	sigma;
	float	sum;
	float	*gauss_tab;

	sigma = GAUSS_RADIUS * 0.5;
	radius = GAUSS_RADIUS;
	sum = 0;
	gauss_tab = ft_gc_malloc((radius * 2 + 1), sizeof(float), rt_type);
	dx = -radius;
	while (dx <= radius)
	{
		gauss_tab[dx + radius] = exp(-(float)(dx * dx) / (2.0f * sigma
					* sigma));
		sum += gauss_tab[dx + radius];
		dx++;
	}
	dx = -radius;
	while (dx <= radius)
	{
		gauss_tab[dx + radius] = gauss_tab[dx + radius] / sum;
		dx++;
	}
	return (gauss_tab);
}

float	ft_clampf(float a, float min, float max)
{
	if (a < min)
		return (min);
	if (a > max)
		return (max);
	return (a);
}

float	ft_rand(void)
{
	static _Thread_local unsigned int	xorshift_state = 42;

	xorshift_state ^= xorshift_state << 13;
	xorshift_state ^= xorshift_state >> 17;
	xorshift_state ^= xorshift_state << 5;
	return (xorshift_state * (1.0f / 4294967296.0f));
}
