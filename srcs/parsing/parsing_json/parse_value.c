/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:57:45 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:20:11 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_parse_coordinates(char *value, t_vec *coord)
{
	int	i;

	i = 0;
	if (coord->w != 0)
		return (ft_putendl_fd("to many coordinates", 2), 1);
	coord->w += 1;
	if (ft_skip_space(&i, value, 0) || !value[i] || value[i] != '[')
		return (ft_putendl_fd("invalid syntax of coordinates", 2), 1);
	i++;
	if (ft_recup_float(value, &coord->x, &i, 0))
		return (ft_putendl_fd("invalid syntax of coordinates", 2), 1);
	if (ft_recup_float(value, &coord->y, &i, 1))
		return (ft_putendl_fd("invalid syntax of coordinates", 2), 1);
	if (ft_recup_float(value, &coord->z, &i, 4))
		return (ft_putendl_fd("invalid syntax of coordinates", 2), 1);
	if (ft_skip_space(&i, value, 0) || value[i] != ']')
		return (ft_putendl_fd("invalid syntax of coordinates", 2), 1);
	return (0);
}

int	ft_parse_normal(char *value, t_vec *normal)
{
	int	i;

	i = 0;
	if (normal->w != 0)
		return (ft_putendl_fd("multiple normals definition", 2), 1);
	normal->w += 1;
	if (ft_skip_space(&i, value, 0) || !value[i] || value[i] != '[')
		return (ft_putendl_fd("invalid syntax of normal", 2), 1);
	i++;
	if (ft_recup_float(value, &normal->x, &i, 0) || !(normal->x >= -1
			&& normal->x <= 1))
		return (ft_putendl_fd("invalid syntax of normal", 2), 1);
	if (ft_recup_float(value, &normal->y, &i, 1) || !(normal->y >= -1
			&& normal->y <= 1))
		return (ft_putendl_fd("invalid syntax of normal", 2), 1);
	if (ft_recup_float(value, &normal->z, &i, 4) || !(normal->z >= -1
			&& normal->z <= 1))
		return (ft_putendl_fd("invalid syntax of normal", 2), 1);
	if (ft_skip_space(&i, value, 0) || value[i] != ']')
		return (ft_putendl_fd("invalid syntax of normal", 2), 1);
	if (ft_check_normalize(*normal))
		return (1);
	return (0);
}

int	ft_parse_ratio(char *value, float *ratio, char *name)
{
	int	i;

	i = 0;
	if (*ratio != -1)
		return (ft_putstr_fd("multiple  ", 2), ft_putstr_fd(name, 2),
			ft_putendl_fd(" definition", 2), 1);
	if (ft_skip_space(&i, value, 0))
		return (ft_putstr_fd("invalid syntax of ", 2), ft_putendl_fd(name, 2),
			1);
	if (ft_recup_float(value, ratio, &i, 5) || !(*ratio >= 0 && *ratio <= 1))
		return (ft_putstr_fd("invalid syntax of ", 2), ft_putendl_fd(name, 2),
			1);
	if (ft_skip_space(&i, value, 1) || (value[i] && value[i] != ','))
		return (ft_putstr_fd("invalid syntax of ", 2), ft_putendl_fd(name, 2),
			1);
	return (0);
}
