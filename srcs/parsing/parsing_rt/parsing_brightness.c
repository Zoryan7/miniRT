/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_brightness.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:05:52 by ymoumene          #+#    #+#             */
/*   Updated: 2026/03/16 15:49:15 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

static int	ft_add_brightness_float(char *src, float *brightness)
{
	if (ft_verif_dot(src, 1))
		return (1);
	*brightness = ft_atof(src);
	return (0);
}

int	ft_parse_brightness_ambient(char *line, t_mini_rt *rt, int *i)
{
	char	*dest;
	int		len;
	int		j;

	j = *i;
	if (line[j] == '-' || line[j] == '+')
		j++;
	while (line[j] && ((line[j] >= '0' && line[j] <= '9') || line[j] == '.'))
		j++;
	len = j - *i;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (1);
	ft_strlcpy(dest, line + *i, len + 1);
	if (ft_add_brightness_float(dest, &rt->ambient.brightness))
		return (1);
	*i = j;
	free(dest);
	return (0);
}

int	ft_parse_brightness_light(char *line, t_light_info *light, int *i)
{
	char	*dest;
	int		len;
	int		j;

	j = *i;
	if (line[j] == '-' || line[j] == '+')
		j++;
	while (line[j] && ((line[j] >= '0' && line[j] <= '9') || line[j] == '.'))
		j++;
	len = j - *i;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (1);
	ft_strlcpy(dest, line + *i, len + 1);
	if (ft_add_brightness_float(dest, &light->light.brightness))
		return (1);
	*i = j;
	free(dest);
	return (0);
}
