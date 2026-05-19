/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:40:58 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/17 15:32:23 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_maxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}
