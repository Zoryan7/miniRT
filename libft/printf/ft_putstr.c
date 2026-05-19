/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:11:09 by etessoer          #+#    #+#             */
/*   Updated: 2026/05/19 18:46:45 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *str)
{
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return ;

	}
	else
	{
		if (write(1, str, ft_strlen(str)) == -1)
			return ;
	}
}
