/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupper_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:11:11 by etessoer          #+#    #+#             */
/*   Updated: 2025/12/10 16:31:24 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putupper_hexa(unsigned int nb)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
		ft_putupper_hexa(nb / 16);
	ft_putchar(base[nb % 16]);
}
