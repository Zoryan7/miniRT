/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:23:05 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:27:57 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

int	ft_add_texture(char *line, int len, t_parsing *parsing)
{
	char			*path;
	t_texture_info	*dest;

	dest = ft_new_texture();
	if (!dest)
	{
		return (1);
	}
	path = ft_substr(line, 0, len);
	if (!path || ft_add_to_gc(path, maps_type) == NULL)
	{
		return (1);
	}
	dest->texture.name = path;
	ft_add_back_texture(dest, parsing);
	return (0);
}

int	ft_parse_texture_line_rt(char *line, t_parsing *parsing)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (line[0] == 0 || ft_skip_space(&i, line, 0))
		return (0);
	while (line[i + len] && line[i + len] != ' ' && (line[i + len] > 13
			|| line[i + len] < 9))
		len++;
	if (len >= 4 && ft_strncmp(line + (i + len - 4), ".xpm", 4) == 0)
		return (ft_add_texture(line + i, len, parsing));
	return (2);
}

int	ft_parse_texture_rt(char **line, int fd, t_parsing *parsing)
{
	int	i;

	i = 0;
	while (*line)
	{
		i = ft_parse_texture_line_rt(*line, parsing);
		if (i == 1)
			return (1);
		else if (i == 2)
			return (0);
		*line = ft_get_next_line_parsing(fd);
	}
	if (!*line)
		return (1);
	return (0);
}
