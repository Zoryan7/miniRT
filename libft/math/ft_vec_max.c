/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:26:44 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/17 15:32:40 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

t_vec	ft_vec_max(t_vec a, t_vec b)
{
	float	max_x;
	float	max_y;
	float	max_z;

	max_x = ft_maxf(a.x, b.x);
	max_y = ft_maxf(a.y, b.y);
	max_z = ft_maxf(a.z, b.z);
	return ((t_vec){{max_x, max_y, max_z, 0}});
}
