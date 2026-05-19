/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:07:30 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:07:35 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_texture	*ft_add_textures(t_texture_list texture)
{
	t_texture	*dest;
	int			i;

	dest = ft_gc_malloc(texture.size, sizeof(t_texture), maps_type);
	if (!dest)
		return (NULL);
	i = 0;
	while (texture.head)
	{
		dest[i] = texture.head->texture;
		texture.head = texture.head->next;
		i++;
	}
	return (dest);
}
