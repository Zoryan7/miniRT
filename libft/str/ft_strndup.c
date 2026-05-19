/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:43:42 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/05 12:12:54 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s1[i] != '\0' && i < n)
		i++;
	copy = malloc((i + 1) * sizeof(char));
	if (copy)
	{
		i = 0;
		while (s1[i] != '\0' && i < n)
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	else
		return (0);
}
