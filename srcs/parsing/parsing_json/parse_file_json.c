/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_json.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:13:43 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:12:39 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

static int	ft_parse_line_2(char *line, t_parsing *parsing, int fd)
{
	int	i;

	i = 0;
	if (ft_skip_space(&i, line, 1))
		return (0);
	if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"box\"", 7) == 0)
		return (ft_parse_box_json(parsing, fd));
	else if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"plane\"",
			7) == 0)
		return (ft_parse_plane_json(parsing, fd));
	else if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"cylinder\"",
			7) == 0)
		return (ft_parse_cylinder_json(parsing, fd));
	else if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"cone\"", 7) == 0)
		return (ft_parse_cone_json(parsing, fd));
	else if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"rounded_box\"",
			7) == 0)
		return (ft_parse_rounded_box_json(parsing, fd));
	else if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"triangle\"",
			7) == 0)
		return (ft_parse_triangle_json(parsing, fd));
	return (1);
}

static int	ft_parse_line_json(char *line, t_parsing *parsing, t_mini_rt *rt,
		int fd)
{
	int	i;

	i = 0;
	if (ft_skip_space(&i, line, 1) || !line[i])
		return (0);
	if (line[i] == '{' || line[i] == '}')
	{
		i++;
		if (ft_skip_space(&i, line, 0) || line[i] == '\n' || line[i] == 0)
			return (0);
	}
	if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"ambient\"", 7) == 0)
		return (ft_parse_ambient_json(rt, parsing, fd));
	else if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"camera\"",
			7) == 0)
		return (ft_parse_camera_json(rt, parsing, fd));
	else if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"light\"",
			7) == 0)
		return (ft_parse_light_json(parsing, fd));
	else if (line[i] && line[i + 1] && ft_cmp_key(line + i, "\"sphere\"",
			7) == 0)
		return (ft_parse_sphere_json(parsing, fd));
	return (ft_parse_line_2(line, parsing, fd));
}

int	ft_parse_file_json(char *file, t_parsing *parsing, t_mini_rt *rt)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_parse_line_json(line, parsing, rt, fd))
			return (free(line), close(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (parsing->ambient == 0 || parsing->camera == 0
		|| parsing->light.head == NULL || parsing->object.head == NULL)
		return (1);
	return (0);
}
