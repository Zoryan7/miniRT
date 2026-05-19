/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:27:12 by etessoer          #+#    #+#             */
/*   Updated: 2025/12/15 17:33:38 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "../libc/libc.h"

// Printf Func
void	ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putlower_hexa(unsigned int nb);
void	ft_putvoid(void *ad);
void	ft_putunnbr(unsigned int nb);
void	ft_putupper_hexa(unsigned int nb);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

#endif