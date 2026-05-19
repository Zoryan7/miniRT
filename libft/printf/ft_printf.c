/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:21:50 by etessoer          #+#    #+#             */
/*   Updated: 2025/12/16 17:08:56 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_print_param(va_list arg_ptr, char c)
{
	if (c == 'c')
		ft_putchar(va_arg(arg_ptr, int));
	else if (c == 's')
		ft_putstr(va_arg(arg_ptr, char *));
	else if (c == 'p')
		ft_putvoid(va_arg(arg_ptr, void *));
	else if (c == 'd')
		ft_putnbr(va_arg(arg_ptr, int));
	else if (c == 'i')
		ft_putnbr(va_arg(arg_ptr, int));
	else if (c == 'u')
		ft_putunnbr(va_arg(arg_ptr, unsigned int));
	else if (c == 'x')
		ft_putlower_hexa(va_arg(arg_ptr, int));
	else if (c == 'X')
		ft_putupper_hexa(va_arg(arg_ptr, int));
	else if (c == '%')
		ft_putchar('%');
}

static int	ft_is_param(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_printf(const char *str, ...)
{
	va_list		arg_ptr;
	size_t		i;

	i = 0;
	if (!str)
		return ;
	va_start(arg_ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (ft_is_param(str[i + 1]))
				ft_print_param(arg_ptr, str[i + 1]);
			else
				return ;
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(arg_ptr);
}
