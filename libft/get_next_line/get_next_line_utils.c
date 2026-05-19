/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:28:35 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/05 12:12:37 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	start_checks(int fd, char **stash, char **buffer)
{
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	if (!stash[fd])
		stash[fd] = ft_alloc(1);
	if (!stash[fd])
		return (0);
	*buffer = ft_alloc(BUFFER_SIZE + 1);
	if (!*buffer)
		return (0);
	return (1);
}

void	*ft_alloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (i < size)
		ptr[i++] = 0;
	return (ptr);
}
