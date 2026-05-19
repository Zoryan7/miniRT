/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:34:51 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/05 12:12:37 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnlsrc(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		i++;
		return (i);
	}
	return (0);
}

char	*join(char *stash, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new = ft_alloc(strlen(stash) + strlen(buffer) + 1);
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	while (stash[++i])
		new[i] = stash[i];
	while (buffer[++j])
		new[i + j] = buffer[j];
	free(stash);
	return (new);
}

char	*gnl_extract(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_alloc(i + 1);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_clean(char *stash)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	if (stash[i] == '\n')
		i++;
	new = ft_alloc(strlen(stash) - i + 1);
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash[1024];
	char		*line;
	int			bytes;

	if (!start_checks(fd, stash, &buffer))
		return (NULL);
	bytes = 1;
	while (!gnlsrc(stash[fd]) && bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(stash[fd]), stash[fd] = NULL);
		buffer[bytes] = '\0';
		stash[fd] = join(stash[fd], buffer);
	}
	if (!*stash[fd])
		return (free(buffer), free(stash[fd]), stash[fd] = NULL);
	return (free(buffer), line = gnl_extract(stash[fd]),
		stash[fd] = gnl_clean(stash[fd]), line);
}

/* int	main(void)
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
} */