/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_json_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:28:05 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:33:16 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

static int	ft_end_or_empty(char *line, int *i)
{
	if (ft_skip_space(i, line, 0) || line[*i] == '\n' || line[*i] == 0)
		return (1);
	return (0);
}

static int	ft_check_brackets(char *line, int pos, int *i)
{
	if (pos == 0 && line[*i] == '{')
	{
		(*i)++;
		if (ft_end_or_empty(line, i))
			return (0);
	}
	if ((pos == 1 || pos == 2) && line[*i] == '}')
	{
		(*i)++;
		if (ft_end_or_empty(line, i))
			return (0);
		if (line[*i] == ',')
			(*i)++;
		if (ft_end_or_empty(line, i))
			return (0);
	}
	return (-1);
}

int	ft_check_in_out_object(char *line, int pos)
{
	int	i;

	i = 0;
	if (!line)
		return (ft_putstr_fd("incomplete object", 2), 1);
	if (ft_skip_space(&i, line, 0))
		return (ft_putstr_fd("invalid syntax", 2), 1);
	if (ft_check_brackets(line, pos, &i) == 0)
		return (0);
	if (pos == 2)
		return (1);
	return (ft_putstr_fd("invalid syntax", 2), 1);
}
