/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:34:19 by etessoer          #+#    #+#             */
/*   Updated: 2025/10/09 16:34:19 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static int	ft_strlen_itoa(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*dst;
	long	nb;

	nb = n;
	i = ft_strlen_itoa(nb);
	sign = 0;
	dst = malloc(i + 1 * sizeof(char));
	if (nb < 0)
	{
		sign = 1;
		nb *= -1;
	}
	dst[i] = '\0';
	i--;
	while (i >= sign)
	{
		dst[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	if (sign == 1)
		dst[0] = '-';
	return (dst);
}
