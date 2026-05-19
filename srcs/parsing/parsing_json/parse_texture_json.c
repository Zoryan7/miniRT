/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_json.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 09:08:13 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:20:35 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

char	*ft_find_path_texture(char *value)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	while (value[j] && value[j] != '\"')
		j++;
	if (value[j] != '\"')
		return (NULL);
	j++;
	while (value[i + j] && value[i + j] != '\"')
		i++;
	if (value[i + j] != '\"')
		return (NULL);
	path = ft_substr(value, j, i);
	if (!path || ft_add_to_gc(path, maps_type) == NULL)
		return (NULL);
	return (path);
}

int	ft_search_path_textures(t_texture_list *textures, char *path)
{
	int				i;
	t_texture_info	*temp;

	i = 0;
	temp = textures->head;
	while (temp)
	{
		if (temp && ft_strcmp(path, temp->texture.name) == 0)
			return (i);
		temp = temp->next;
		i++;
	}
	return (-1);
}

int	ft_create_new_texture(t_texture_list *textures, char *path)
{
	t_texture_info	*dest;

	dest = ft_new_texture();
	if (!dest)
		return (-1);
	dest->texture.name = path;
	if (textures->size == 0)
	{
		textures->head = dest;
		textures->tail = dest;
	}
	else
	{
		textures->tail->next = dest;
		textures->tail = dest;
	}
	textures->size++;
	return (textures->size - 1);
}

int	ft_parse_textures_json(t_texture_list *textures, char *line, int *dest,
		char *name)
{
	char	*path;

	if (*dest != -1)
		return (ft_putstr_fd("to many ", 2), ft_putstr_fd(name, 2),
			ft_putstr_fd("defined", 2), 1);
	path = ft_find_path_texture(line);
	if (!path)
		return (1);
	*dest = ft_search_path_textures(textures, path);
	if (*dest == -1)
	{
		*dest = ft_create_new_texture(textures, path);
		if (*dest == -1)
			return (1);
	}
	return (0);
}
