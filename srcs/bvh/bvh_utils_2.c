/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:06:26 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 05:05:12 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

t_aabb	ft_recup_min_max(t_object object)
{
	t_aabb	temp;

	temp.min = ft_calcul_min(object);
	temp.max = ft_calcul_max(object);
	return (temp);
}

t_aabb	ft_grow_bvh(t_bvh *dest, t_mini_rt *rt)
{
	int		i;
	t_aabb	temp;
	t_aabb	global_box;

	i = 0;
	global_box = ft_initialize_global_box();
	temp = ft_initialize_global_box();
	while (i < dest->nb_object)
	{
		temp = ft_recup_min_max(rt->object[dest->index_object[i]]);
		ft_compare_temp_with_global(temp, &global_box, rt->camera.coord);
		i++;
	}
	return (global_box);
}

void	ft_split_bvh_2(t_bvh **left, t_bvh **right, t_mini_rt *rt, int lvl)
{
	if ((*left)->nb_object > 0)
	{
		(*left)->aabb = ft_grow_bvh(*left, rt);
		(*left)->lvl = lvl + 1;
	}
	else
	{
		*left = NULL;
	}
	if ((*right)->nb_object > 0)
	{
		(*right)->aabb = ft_grow_bvh(*right, rt);
		(*right)->lvl = lvl + 1;
	}
	else
	{
		*right = NULL;
	}
}

int	ft_affect_to_each_object(t_bvh *parent, t_bvh *left, t_bvh *right,
		t_mini_rt *rt)
{
	int	i;

	i = 0;
	while (i < parent->nb_object)
	{
		if (ft_which_side_bvh(i, parent, rt))
		{
			left->index_object[left->nb_object] = parent->index_object[i];
			left->nb_object++;
		}
		else
		{
			right->index_object[right->nb_object] = parent->index_object[i];
			right->nb_object++;
		}
		i++;
	}
	if (left->nb_object == 0 || right->nb_object == 0
		|| left->nb_object == parent->nb_object
		|| right->nb_object == parent->nb_object)
		return (1);
	return (0);
}
