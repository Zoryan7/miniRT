/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:14:40 by etessoer          #+#    #+#             */
/*   Updated: 2025/09/18 18:14:40 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

static void	ft_back_to_front(unsigned char *d, unsigned char *s, size_t n)
{
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
}

static void	ft_front_to_back(unsigned char *d, unsigned char *s, size_t n)
{
	while (n > 0)
	{
		n--;
		*d = *s;
		d++;
		s++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dest;
	s = (unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	if (d > s && d < s + n)
		ft_back_to_front(d, s, n);
	else
		ft_front_to_back(d, s, n);
	return (dest);
}
