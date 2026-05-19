/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:18:05 by ymoumene          #+#    #+#             */
/*   Updated: 2026/05/18 14:21:52 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_parse_fov(char *value, unsigned char *fov, int *nb_fov)
{
	int		i;
	char	dest[5];

	i = 0;
	if (*nb_fov != 0)
		return (ft_putendl_fd("multiple fov definition", 2), 1);
	*nb_fov += 1;
	if (ft_skip_space(&i, value, 0))
		return (ft_putendl_fd("invalid syntax of fov", 2), 1);
	if (ft_recup_color(dest, value, &i, 3)
		|| ft_char_to_color_fov(fov, dest) || !(*fov <= 180))
		return (ft_putendl_fd("invalid syntax of fov", 2), 1);
	return (0);
}

int	ft_parse_single_float(char *value, float *dest, char *name)
{
	int	i;

	i = 0;
	if (*dest != -1)
		return (ft_putstr_fd("multiple ", 2), ft_putstr_fd(name, 2),
			ft_putendl_fd(" definition", 2), 1);
	if (ft_skip_space(&i, value, 0))
		return (ft_putstr_fd("invalid syntax of ", 2), ft_putendl_fd(name, 2),
			1);
	if (ft_recup_float(value, dest, &i, 5))
		return (ft_putstr_fd("invalid syntax of ", 2), ft_putendl_fd(name, 2),
			1);
	if (ft_skip_space(&i, value, 1) || (value[i] && value[i] != ','))
		return (ft_putstr_fd("invalid syntax of ", 2), ft_putendl_fd(name, 2),
			1);
	return (0);
}

int	ft_parse_color(char *value, t_vec *color)
{
	int	i;

	i = 0;
	if (color->t != 0)
		return (ft_putstr_fd("multiple color definition", 2), 1);
	color->t += 1;
	if (ft_skip_space(&i, value, 0) || !value[i] || value[i] != '[')
		return (ft_putstr_fd("invalid syntax of color", 2), 1);
	i++;
	if (ft_recup_float(value, &color->r, &i, 0) || !(color->r >= 0
			&& color->r <= 255))
		return (ft_putstr_fd("invalid syntax of color", 2), 1);
	color->r = color->r / 255.0f;
	if (ft_recup_float(value, &color->g, &i, 1) || !(color->g >= 0
			&& color->g <= 255))
		return (ft_putstr_fd("invalid syntax of color", 2), 1);
	color->g = color->g / 255.0f;
	if (ft_recup_float(value, &color->b, &i, 4) || !(color->b >= 0
			&& color->b <= 255))
		return (ft_putstr_fd("invalid syntax of color", 2), 1);
	color->b = color->b / 255.0f;
	if (ft_skip_space(&i, value, 0) || value[i] != ']')
		return (ft_putstr_fd("invalid syntax of color", 2), 1);
	return (0);
}
