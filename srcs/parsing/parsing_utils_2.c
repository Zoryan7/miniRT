/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:37:14 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:08:19 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_get_next_line_parsing(int fd)
{
	char	*dest;

	dest = get_next_line(fd);
	if (!ft_add_to_gc(dest, parsing_type))
		return (free(dest), NULL);
	return (dest);
}

int	ft_verif_dot(char *src, int nb)
{
	int	i;

	i = 0;
	if (src[i] == '-' || src[i] == '+')
		i++;
	if (src[i] == '.')
		return (1);
	while (src[i + 1])
	{
		if (src[i] == '.')
			nb--;
		i++;
	}
	if (src[i] == '.')
		return (1);
	if (nb < 0)
		return (1);
	return (0);
}

void	ft_add_back_object(t_object_info *new, t_parsing *parsing)
{
	if (parsing->object.size == 0)
	{
		parsing->object.head = new;
		parsing->object.tail = new;
	}
	else
	{
		parsing->object.tail->next = new;
		parsing->object.tail = new;
	}
	parsing->object.size++;
}

void	ft_add_back_light(t_light_info *new, t_parsing *parsing)
{
	if (parsing->light.size == 0)
	{
		parsing->light.head = new;
		parsing->light.tail = new;
	}
	else
	{
		parsing->light.tail->next = new;
		parsing->light.tail = new;
	}
	parsing->light.size++;
}

void	ft_add_back_texture(t_texture_info *new, t_parsing *parsing)
{
	if (parsing->texture.size == 0)
	{
		parsing->texture.head = new;
		parsing->texture.tail = new;
	}
	else
	{
		parsing->texture.tail->next = new;
		parsing->texture.tail = new;
	}
	parsing->texture.size++;
}
