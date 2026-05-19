/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:23:26 by etessoer          #+#    #+#             */
/*   Updated: 2025/09/30 18:23:26 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static int	ft_nb_word(char const *s)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	while (s[i - 1] != '\0')
	{
		if (!ft_is_whitespace(s[i - 1]) && (ft_is_whitespace(s[i])
				|| s[i] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

static void	ft_write_lign(char const *s, char *split, int *i)
{
	int	j;

	j = 0;
	while (!ft_is_whitespace(s[*i]) && s[*i] != '\0')
	{
		split[j] = s[*i];
		(*i)++;
		j++;
	}
	split[j] = '\0';
}

static void	ft_free(char **split, int word)
{
	while (word != 0)
	{
		free(split[word]);
		word--;
	}
	free(split);
}

static int	ft_malloc_lign(char const *s, char **split, int nb_word)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0' && word < nb_word)
	{
		while (ft_is_whitespace(s[i]))
			i++;
		j = 0;
		while (!ft_is_whitespace(s[i + j]) && s[i + j] != '\0')
			j++;
		split[word] = malloc(j + 1);
		if (!split[word])
		{
			ft_free(split, word);
			return (0);
		}
		ft_write_lign(s, split[word], &i);
		word++;
	}
	split[word] = NULL;
	return (1);
}

char	**ft_split_whitespace(char const *s)
{
	char	**split;

	split = malloc((ft_nb_word(s) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!ft_malloc_lign(s, split, ft_nb_word(s)))
		return (NULL);
	return (split);
}
