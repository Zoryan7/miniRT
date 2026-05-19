/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:43:27 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 02:57:20 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_verif_next_char_float2(int pos, char c)
{
	if (pos == 5)
	{
		if (c != ' ' && c != '\n' && c != ',' && c != '\0')
			return (1);
	}
	return (0);
}

int	ft_verif_next_char_float(int pos, char c, int *i)
{
	if (pos < 2)
	{
		if (c != ',')
			return (1);
		(*i)++;
	}
	if (pos == 2)
	{
		if (c != ' ')
			return (1);
	}
	if (pos == 3)
	{
		if (c != ' ' && c != '\n' && c != '\0')
			return (1);
	}
	if (pos == 4)
	{
		if (c != ' ' && c != '\n' && c != ']' && c != '\0')
			return (1);
	}
	return (ft_verif_next_char_float2(pos, c));
}

int	ft_recup_float_char(char *line, char *dest, int *i, int pos)
{
	int	j;

	j = 0;
	if (line[*i + j] == '+' || line[*i + j] == '-')
	{
		dest[j] = line[*i + j];
		j++;
	}
	while ((line[*i + j] <= '9' && line[*i + j] >= '0') || line[*i + j] == '.')
	{
		dest[j] = line[*i + j];
		j++;
	}
	*i += j;
	dest[j] = '\0';
	if (ft_verif_next_char_float(pos, line[*i], i))
		return (1);
	return (0);
}

int	ft_verif_overflow(char *line, int i)
{
	int	j;

	j = 0;
	if (line[i + j] == '+' || line[i + j] == '-')
		j++;
	while ((line[i + j] <= '9' && line[i + j] >= '0') || line[i + j] == '.')
		j++;
	if (j > 127)
		return (1);
	return (0);
}

int	ft_recup_float(char *line, float *dest, int *i, int pos)
{
	char	*coord_c;

	if (ft_skip_space(i, line, 0))
		return (1);
	coord_c = ft_calloc(1, 128);
	if (!coord_c)
		return (1);
	if (ft_verif_overflow(line, *i) || ft_recup_float_char(line, coord_c, i,
			pos) || ft_verif_dot(coord_c, 1))
		return (1);
	*dest = ft_atof(coord_c);
	free(coord_c);
	return (0);
}
