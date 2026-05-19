/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:16:56 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/17 15:20:16 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

t_vec	ft_vec_sign(t_vec vec)
{
	int	sign_x;
	int	sign_y;
	int	sign_z;

	sign_x = ft_signf(vec.x);
	sign_y = ft_signf(vec.y);
	sign_z = ft_signf(vec.z);
	return ((t_vec){{sign_x, sign_y, sign_z, 0}});
}
