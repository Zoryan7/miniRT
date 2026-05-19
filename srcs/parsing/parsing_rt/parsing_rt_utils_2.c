/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rt_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:46:53 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:49:21 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_triple_recup_float_1(char *line, t_vec *vec, int *i)
{
	if (ft_recup_float(line, &vec->x, i, 0))
		return (1);
	if (ft_recup_float(line, &vec->y, i, 1))
		return (1);
	if (ft_recup_float(line, &vec->z, i, 2))
		return (1);
	return (0);
}

int	ft_triple_recup_float_2(char *line, t_vec *vec, int *i)
{
	if (ft_recup_float(line, &vec->x, i, 0) || !(vec->x >= -1 && vec->x <= 1))
		return (1);
	if (ft_recup_float(line, &vec->y, i, 1) || !(vec->y >= -1 && vec->y <= 1))
		return (1);
	if (ft_recup_float(line, &vec->z, i, 2) || !(vec->z >= -1 && vec->z <= 1))
		return (1);
	return (0);
}

int	ft_triple_recup_float_3(char *line, t_vec *vec, int *i)
{
	if (ft_recup_float(line, &vec->x, i, 0) || !(vec->x > 0))
		return (1);
	if (ft_recup_float(line, &vec->y, i, 1) || !(vec->y > 0))
		return (1);
	if (ft_recup_float(line, &vec->z, i, 2) || !(vec->z > 0))
		return (1);
	return (0);
}
