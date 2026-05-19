/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:39:18 by etessoer          #+#    #+#             */
/*   Updated: 2026/05/18 14:42:47 by etessoer         ###   ########.fr       */
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
	return (count + 1);
}

char	*ft_init_itoa(float *n, t_itoa_float *info)
{
	if (*n == 0.0f)
		return ("0");
	info->zero = 0;
	if (*n > 0.0f && *n < 1.0f)
		info->zero = 1;
	*n = *n * 100;
	info->nb = *n;
	info->len = ft_strlen_itoa(info->nb) + info->zero;
	info->ini_len = info->len;
	if (info->nb < 0)
		info->nb = -info->nb;
	return ("1");
}

char	*ft_itoa_float(float n)
{
	static char		dst[12];
	t_itoa_float	info;

	info.ini_len = 0;
	info.len = 0;
	info.nb = 0;
	info.zero = 0;
	if (!ft_strcmp(ft_init_itoa(&n, &info), "0"))
		return ("0");
	dst[info.len] = '\0';
	while (info.len--)
	{
		if (info.len == info.ini_len - 3)
			dst[info.len] = '.';
		else
		{
			dst[info.len] = (info.nb % 10) + '0';
			info.nb /= 10;
			if (info.nb == 0 && !info.zero)
				break ;
		}
	}
	if (info.zero && n < 0)
		dst[1] = '0';
	else if (info.zero)
		dst[0] = '0';
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
