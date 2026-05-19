/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:33:19 by etessoer          #+#    #+#             */
/*   Updated: 2026/02/05 20:33:25 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	ft_len_file(char *file)
{
	int		len;
	char	*line;
	int		fd;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}
