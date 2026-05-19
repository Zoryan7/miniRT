/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:38:37 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:27:45 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_rt.h"

static int	ft_parse_line_2(char *line, t_parsing *parsing, int i)
{
	if (line[i] && line[i + 1] && ft_strncmp(line + i, "sp", 2) == 0)
		return (ft_parse_object(line + i, parsing, 0));
	else if (line[i] && line[i + 1] && ft_strncmp(line + i, "pl", 2) == 0)
		return (ft_parse_object(line + i, parsing, 1));
	else if (line[i] && line[i + 1] && ft_strncmp(line + i, "cy", 2) == 0)
		return (ft_parse_object(line + i, parsing, 2));
	else if (line[i] && line[i + 1] && ft_strncmp(line + i, "co", 2) == 0)
		return (ft_parse_object(line + i, parsing, 3));
	else if (line[i] && line[i + 1] && ft_strncmp(line + i, "rb", 2) == 0)
		return (ft_parse_object(line + i, parsing, 4));
	else if (line[i] && line[i + 1] && ft_strncmp(line + i, "tr", 2) == 0)
		return (ft_parse_object(line + i, parsing, 5));
	else if (line[i] && line[i + 1] && ft_strncmp(line + i, "bo", 2) == 0)
		return (ft_parse_object(line + i, parsing, 6));
	return (1);
}

static int	ft_parse_line(char *line, t_parsing *parsing, t_mini_rt *rt)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] == 32)
		i++;
	if (!line[i] || !ft_strcmp(line + i, "\n"))
		return (0);
	if (line[i] && line[i] == 'A')
		return (ft_parse_ambient(line + i, rt, parsing));
	else if (line[i] && line[i] == 'C')
		return (ft_parse_camera(line + i, rt, parsing));
	else if (line[i] && line[i] == 'L')
		return (ft_parse_light(line + i, parsing));
	return (ft_parse_line_2(line, parsing, i));
}

int	ft_parse_file_rt(char *file, t_parsing *parsing, t_mini_rt *rt)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	line = ft_get_next_line_parsing(fd);
	if (ft_parse_texture_rt(&line, fd, parsing))
		return (close(fd), 1);
	while (line)
	{
		if (ft_parse_line(line, parsing, rt))
			return (close(fd), 1);
		line = ft_get_next_line_parsing(fd);
	}
	close(fd);
	if (parsing->ambient == 0 || parsing->camera == 0
		|| parsing->light.head == NULL || parsing->object.head == NULL)
		return (1);
	return (0);
}
