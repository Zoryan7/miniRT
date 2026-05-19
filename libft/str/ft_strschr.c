/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:27:35 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/05 12:12:37 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	ft_strschr(char *s1, char *s2)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_strlen(s2);
	while (s1 && s1[i])
	{
		j = 0;
		while (s2 && s2[j] && s1[i + j] == s2[j])
		{
			j++;
			if (j == size)
				return (size);
		}
		i++;
	}
	return (0);
}
