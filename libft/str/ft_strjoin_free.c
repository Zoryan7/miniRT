/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:36:16 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/05 12:12:37 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strjoin_ff(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*join;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(total_len + 1);
	if (!join)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*ft_strjoin_fs(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*join;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(total_len + 1);
	if (!join)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	free(s2);
	return (join);
}

char	*ft_strjoin_df(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*join;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(total_len + 1);
	if (!join)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (free(s1), free(s2), join);
}
