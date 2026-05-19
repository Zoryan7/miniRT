/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:38:22 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 22:45:23 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_check_normalize(t_vec vec)
{
	float	normal;

	if (ft_absf(vec.x) > 1.0f || ft_absf(vec.y) > 1.0f || ft_absf(vec.z) > 1.0f)
		return (ft_putendl_fd("Error: Vector is not normalized", 2), 1);
	normal = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	if (fabsf(normal - 1.0f) > 0.001f)
	{
		return (ft_putendl_fd("Error: Vector is not normalized", 2), 1);
	}
	return (0);
}

void	ft_add_map_gc(char **splited_maps)
{
	int	i;

	i = 0;
	while (splited_maps[i])
	{
		ft_add_to_gc(splited_maps[i], maps_type);
		i++;
	}
	ft_add_to_gc(splited_maps, maps_type);
}

int	ft_check_index_texture(t_object *dest, int size, int size_texture)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (dest[i].id_bump >= size_texture
			|| dest[i].id_texture >= size_texture)
			return (ft_put_error("Error: Texture index is out of bounds\n", 2),
				1);
		i++;
	}
	return (0);
}

int	ft_verif_file_name(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len >= 4 && ft_strcmp(file + (len - 3), ".rt") == 0)
		return (0);
	if (len >= 6 && ft_strcmp(file + (len - 5), ".json") == 0)
		return (1);
	return (-1);
}

t_object	*ft_join_object(t_object *obj, int size_obj, t_object *general,
		t_object *control)
{
	t_object	*all_obj;
	int			i;
	int			len;

	len = size_obj + 31 + 25;
	all_obj = ft_gc_malloc(len, sizeof(t_object), maps_type);
	i = 0;
	while (i < size_obj)
	{
		all_obj[i] = obj[i];
		i++;
	}
	while (i < size_obj + 31)
	{
		all_obj[i] = general[i - size_obj];
		i++;
	}
	while (i < len)
	{
		all_obj[i] = control[i - size_obj - 31];
		i++;
	}
	return (all_obj);
}
