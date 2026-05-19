/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:11:01 by etessoer          #+#    #+#             */
/*   Updated: 2025/12/10 16:31:29 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_puthexa(unsigned long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_puthexa(nb / 16);
	ft_putchar(base[nb % 16]);
}

void	ft_putvoid(void *ad)
{
	if (!ad)
		ft_putstr("(nil)");
	else
	{
		ft_putstr("0x");
		ft_puthexa((unsigned long)ad);
	}
}
