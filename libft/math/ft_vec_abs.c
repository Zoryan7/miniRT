/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:23:34 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 10:15:17 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

t_vec	ft_vec_abs(t_vec vec)
{
	return ((t_vec){{ft_absf(vec.x), ft_absf(vec.y), ft_absf(vec.z),
			ft_absf(vec.w)}});
}
