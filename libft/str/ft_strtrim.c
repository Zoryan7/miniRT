/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:31:15 by etessoer          #+#    #+#             */
/*   Updated: 2025/09/25 21:31:15 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static int	ft_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*trim;

	i = 0;
	x = 0;
	j = ft_strlen(s1) - 1;
	while (ft_is_set(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (ft_is_set(s1[j], set))
		j--;
	trim = malloc(ft_strlen(s1) - i - (ft_strlen(s1) - j) + 2);
	if (!trim)
		return (NULL);
	while (s1[i] && i != j + 1)
	{
		trim[x] = s1[i];
		x++;
		i++;
	}
	trim[x] = '\0';
	return (trim);
}
