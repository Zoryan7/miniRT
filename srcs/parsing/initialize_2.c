/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:32:36 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 08:41:01 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**ft_initialize_rt_maps(t_mini_rt *rt)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*maps;
	char			**splited_maps;

	int (i) = 0;
	dir = opendir("maps/rt/");
	if (!dir)
		return (NULL);
	entry = readdir(dir);
	maps = NULL;
	while (entry != NULL)
	{
		if (entry && ft_strncmp(".", entry->d_name, 1))
		{
			maps = ft_strjoin_ff(maps, entry->d_name);
			maps = ft_strjoin_ff(maps, " ");
			i++;
		}
		entry = readdir(dir);
	}
	rt->info.nb_maps_rt = i;
	closedir(dir);
	splited_maps = ft_split(maps, ' ');
	return (ft_add_map_gc(splited_maps), free(maps), splited_maps);
}

char	**ft_initialize_json_maps(t_mini_rt *rt)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*maps;
	char			**splited_maps;

	int (i) = 0;
	dir = opendir("maps/json/");
	if (!dir)
		return (NULL);
	entry = readdir(dir);
	maps = NULL;
	while (entry != NULL)
	{
		if (entry && ft_strncmp(".", entry->d_name, 1))
		{
			maps = ft_strjoin_ff(maps, entry->d_name);
			maps = ft_strjoin_ff(maps, " ");
			i++;
		}
		entry = readdir(dir);
	}
	rt->info.nb_maps_json = i;
	closedir(dir);
	splited_maps = ft_split(maps, ' ');
	return (ft_add_map_gc(splited_maps), free(maps), splited_maps);
}

t_light_info	*ft_new_light(void)
{
	t_light_info	*dest;

	dest = ft_gc_malloc(1, sizeof(t_light_info), maps_type);
	if (!dest)
		return (NULL);
	dest->next = NULL;
	dest->light.brightness = -1;
	dest->light.radius = 0;
	dest->light.id_texture = -1;
	dest->light.id_bump = -1;
	dest->light.color.r = 0;
	dest->light.color.g = 0;
	dest->light.color.b = 0;
	dest->light.coord.x = 0;
	dest->light.coord.y = 0;
	dest->light.coord.z = 0;
	return (dest);
}

t_object_info	*ft_new_object(void)
{
	t_object_info	*dest;

	dest = ft_gc_malloc(1, sizeof(t_object_info), maps_type);
	if (!dest)
		return (NULL);
	dest->next = NULL;
	dest->object.color.r = 0;
	dest->object.color.g = 0;
	dest->object.color.b = 0;
	dest->object.coord.x = 0;
	dest->object.coord.y = 0;
	dest->object.coord.z = 0;
	dest->object.vec.x = 0;
	dest->object.vec.y = 0;
	dest->object.vec.z = 0;
	dest->object.rot_x = 0;
	dest->object.rot_y = 0;
	dest->object.id_bump = -1;
	dest->object.id_texture = -1;
	return (dest);
}

t_texture_info	*ft_new_texture(void)
{
	t_texture_info	*dest;

	dest = ft_gc_malloc(1, sizeof(t_texture_info), maps_type);
	if (!dest)
		return (NULL);
	dest->next = NULL;
	dest->texture.name = NULL;
	return (dest);
}
