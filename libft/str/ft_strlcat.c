/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:03:38 by etessoer          #+#    #+#             */
/*   Updated: 2025/12/15 17:31:29 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strlcat(char *dest, const char *src, size_t siz)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;
	size_t	j;

	i = 0;
	src_len = ft_strlen(src);
	if (siz == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (siz <= dest_len)
		return (src_len + siz);
	j = 0;
	while (dest[j] && j < siz)
		j++;
	while (src[i] != '\0' && (i + j < siz - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (j + i < siz)
		dest[j + i] = '\0';
	return (src_len + j);
}
