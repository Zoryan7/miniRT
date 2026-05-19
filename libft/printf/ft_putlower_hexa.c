/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlower_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:11:04 by etessoer          #+#    #+#             */
/*   Updated: 2025/12/10 16:31:14 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putlower_hexa(unsigned int nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_putlower_hexa(nb / 16);
	ft_putchar(base[nb % 16]);
}
