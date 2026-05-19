/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rt_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:04:37 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:39:03 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_skip_space(int *i, char *line, int pos)
{
	while (line && line[*i] && ft_is_whitespace(line[*i]))
		(*i)++;
	if (!line[*i] && pos == 0)
		return (1);
	return (0);
}

float	ft_diameter(t_object_info *object)
{
	if (object->object.type == cylinder)
		return (object->object.specificites.cylinder.diameter * 2.0f);
	if (object->object.type == sphere)
		return (object->object.specificites.sphere.diameter * 2.0f);
	if (object->object.type == cone)
		return (object->object.specificites.cone.diameter * 2.0f);
	return (0);
}

float	ft_radius(t_object_info *object)
{
	if (object->object.type == cylinder)
		return (object->object.specificites.cylinder.diameter * 0.5f);
	if (object->object.type == sphere)
		return (object->object.specificites.sphere.diameter * 0.5f);
	if (object->object.type == cone)
		return (object->object.specificites.cone.diameter * 0.5f);
	return (0);
}
