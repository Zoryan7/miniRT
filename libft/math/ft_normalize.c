/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:32:00 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/16 11:15:37 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

t_vec	ft_vec_normalize(t_vec v)
{
	float	len;

	len = ft_vec_length(v);
	return (ft_vec_scale(v, 1.0 / len));
}
