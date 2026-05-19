/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:41:29 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/14 15:14:57 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_minf(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}
