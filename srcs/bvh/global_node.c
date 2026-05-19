/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:20:05 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 04:36:27 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

t_aabb	ft_initialize_global_box(void)
{
	t_aabb	global_box;

	global_box.min.x = FLT_MAX;
	global_box.min.y = FLT_MAX;
	global_box.min.z = FLT_MAX;
	global_box.max.x = -FLT_MAX;
	global_box.max.y = -FLT_MAX;
	global_box.max.z = -FLT_MAX;
	return (global_box);
}

int	ft_calcul_nb_object_root(t_object *object, int size, int *index_object)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (object[i].type != plane)
		{
			index_object[j] = i;
			j++;
		}
		i++;
	}
	return (j);
}

t_aabb	ft_first_bounding_box(t_mini_rt *rt)
{
	int		i;
	t_aabb	temp;
	t_aabb	global_box;

	i = 0;
	global_box = ft_initialize_global_box();
	temp = ft_initialize_global_box();
	while (i < rt->size_object)
	{
		if (rt->object[i].type != plane)
		{
			temp = ft_recup_min_max(rt->object[i]);
			ft_compare_temp_with_global(temp, &global_box, rt->camera.coord);
		}
		i++;
	}
	return (global_box);
}

t_bvh_array	*ft_global_node(t_mini_rt *rt)
{
	t_bvh_array	*dest;
	t_bvh		*global_node;
	int			nb_object;

	nb_object = ft_count_object_without_plane(rt);
	if (nb_object == 0)
		return (NULL);
	dest = ft_create_array_bvh(nb_object);
	if (!dest)
		return (NULL);
	global_node = ft_new_bvh_node(nb_object);
	if (!global_node)
		return (NULL);
	global_node->aabb = ft_first_bounding_box(rt);
	global_node->nb_object = ft_calcul_nb_object_root(rt->object,
			rt->size_object, global_node->index_object);
	global_node->lvl = 0;
	global_node->left = -1;
	global_node->right = -1;
	dest->bvh[0] = *global_node;
	dest->nb_bvh++;
	return (dest);
}
