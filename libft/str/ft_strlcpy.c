/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:03:41 by etessoer          #+#    #+#             */
/*   Updated: 2025/12/15 17:31:31 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t siz)
{
	size_t	i;
	size_t	taille;

	taille = ft_strlen(src);
	i = 0;
	if (taille + 1 < siz)
	{
		while (i < taille)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	else if (siz != 0)
	{
		while (i < siz - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (taille);
}
