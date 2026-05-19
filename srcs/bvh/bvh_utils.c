/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 09:38:36 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 04:36:20 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

t_bvh_array	*ft_create_array_bvh(int nb)
{
	t_bvh_array	*dest;

	dest = ft_gc_malloc(1, sizeof(t_bvh_array), bvh_type);
	if (!dest)
		return (NULL);
	dest->nb_bvh = 0;
	dest->bvh = ft_gc_malloc(nb * 2, sizeof(t_bvh), bvh_type);
	if (!dest->bvh)
		return (NULL);
	return (dest);
}

int	ft_count_object_without_plane(t_mini_rt *rt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rt->size_object)
	{
		if (rt->object[i].type != plane)
			j++;
		i++;
	}
	return (j);
}

t_bvh	*ft_new_bvh_node(int nb_object)
{
	t_bvh	*dest;

	dest = ft_gc_malloc(1, sizeof(t_bvh), bvh_type);
	if (!dest)
		return (NULL);
	dest->index_object = ft_gc_malloc(nb_object, sizeof(int), bvh_type);
	if (!dest->index_object)
		return (NULL);
	if (nb_object > 0)
		dest->index_object[0] = -1;
	dest->nb_object = 0;
	dest->left = -1;
	dest->right = -1;
	return (dest);
}

void	ft_compare_temp_with_global(t_aabb temp, t_aabb *global_box,
		t_vec origin)
{
	(void)origin;
	if (temp.min.x < global_box->min.x)
		global_box->min.x = temp.min.x;
	if (temp.min.y < global_box->min.y)
		global_box->min.y = temp.min.y;
	if (temp.min.z < global_box->min.z)
		global_box->min.z = temp.min.z;
	if (temp.max.x > global_box->max.x)
		global_box->max.x = temp.max.x;
	if (temp.max.y > global_box->max.y)
		global_box->max.y = temp.max.y;
	if (temp.max.z > global_box->max.z)
		global_box->max.z = temp.max.z;
}
