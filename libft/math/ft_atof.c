/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 21:21:36 by ymoumene          #+#    #+#             */
/*   Updated: 2026/03/06 08:55:07 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

float	ft_atof_decimal(char *src)
{
	float	result;
	int		divisor;
	int		i;

	result = 0;
	divisor = 1;
	i = 0;
	while (src && src[i] && src[i] >= '0' && src[i] <= '9')
	{
		result = result * 10 + (src[i] - '0');
		divisor *= 10;
		i++;
	}
	return (result / divisor);
}

float	ft_atof(char *src)
{
	float	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
			sign = -1;
		i++;
	}
	while (src[i] && src[i] >= '0' && src[i] <= '9')
	{
		result = result * 10 + (src[i] - '0');
		i++;
	}
	if (src[i] == '.')
	{
		i++;
		result += ft_atof_decimal(src + i);
	}
	return (result * sign);
}
