/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:21:19 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/02 11:41:33 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_parse_coord_object(char *line, t_object_info *object, int *i)
{
	float	dest;

	if (ft_recup_float(line, &dest, i, 0))
		return (1);
	object->object.coord.x = dest;
	if (ft_recup_float(line, &dest, i, 1))
		return (1);
	object->object.coord.y = dest;
	if (ft_recup_float(line, &dest, i, 2))
		return (1);
	object->object.coord.z = dest;
	return (0);
}

int	ft_parse_color_object(char *line, t_object_info *object, int *i)
{
	float	dest;
	char	color[5];

	if (ft_recup_color(color, line, i, 0))
		return (1);
	if (ft_char_to_color(&dest, color))
		return (1);
	object->object.color.r = dest;
	if (ft_recup_color(color, line, i, 1))
		return (1);
	if (ft_char_to_color(&dest, color))
		return (1);
	object->object.color.g = dest;
	if (ft_recup_color(color, line, i, 2))
		return (1);
	if (ft_char_to_color(&dest, color))
		return (1);
	object->object.color.b = dest;
	return (0);
}
