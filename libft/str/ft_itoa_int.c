/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:39:18 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/03 15:53:45 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static int	ft_strlen_itoa(long nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_int(int n)
{
	static char	dst[12];
	long		nb;
	int			len;

	nb = n;
	len = ft_strlen_itoa(nb);
	dst[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len--)
	{
		dst[len] = (nb % 10) + '0';
		nb /= 10;
		if (nb == 0)
			break ;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
