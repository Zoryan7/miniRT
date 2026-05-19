/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:14:38 by etessoer          #+#    #+#             */
/*   Updated: 2025/10/17 12:14:38 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

static void	ft_printnb(long nb, int fd)
{
	char	c;

	if (nb >= 10)
		ft_printnb(nb / 10, fd);
	c = nb % 10 + '0';
	if (write(fd, &c, 1) == -1)
		return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		if (write(fd, "-", 1) == -1)
			return ;
	}
	ft_printnb(nb, fd);
}
