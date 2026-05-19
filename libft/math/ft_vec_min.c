/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:30:01 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/17 15:32:39 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

t_vec	ft_vec_min(t_vec a, t_vec b)
{
	float	min_x;
	float	min_y;
	float	min_z;

	min_x = ft_minf(a.x, b.x);
	min_y = ft_minf(a.y, b.y);
	min_z = ft_minf(a.z, b.z);
	return ((t_vec){{min_x, min_y, min_z, 0}});
}
