/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:43:27 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:40:29 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_recup_color(char *color, char *line, int *i, int pos)
{
	int	j;

	j = 0;
	while (line[*i + j] <= '9' && line[*i + j] >= '0')
	{
		color[j] = line[*i + j];
		j++;
	}
	*i += j;
	if (pos < 2)
	{
		if (line[*i] != ',')
			return (1);
		(*i)++;
	}
	if (pos == 2 && (line[*i] != ' ' && line[*i] != '\n'))
		return (1);
	if (pos == 3)
	{
		if (line[*i] != ' ' && line[*i] != '\n' && line[*i] != ',')
			return (1);
	}
	color[j] = '\0';
	return (0);
}

int	ft_char_to_color(float *dest, char *color)
{
	int	result;

	result = ft_atoi(color);
	if (result < 0 || result > 255)
		return (1);
	*dest = (float)result / 255.0f;
	return (0);
}

int	ft_char_to_color_spec(float *dest, char *color)
{
	float	result;

	result = ft_atof(color);
	if (result < 0 || result > 1)
		return (1);
	*dest = result;
	return (0);
}

int	ft_char_to_color_fov(unsigned char *dest, char *color)
{
	int	result;

	result = ft_atoi(color);
	if (result < 30 || result > 180)
		return (1);
	*dest = result;
	return (0);
}
