/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_bvh_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 05:06:58 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 05:55:43 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_vec2	ft_leaf_bvh(t_ray ray, t_bvh *bvh_node, t_mini_rt *rt,
		t_calcul_color *info)
{
	int		i;
	t_vec2	inter;

	i = 0;
	inter.x = -1;
	inter.y = -1;
	while (i < bvh_node->nb_object)
	{
		info->i = bvh_node->index_object[i];
		if (info->i != info->j_obj)
		{
			inter = ft_choose_intersect(rt->object[info->i], ray);
			ft_inter_choice(info, inter);
		}
		i++;
	}
	return (inter);
}

int	ft_leaf_bvh_light(t_ray ray, t_bvh *bvh_node, t_mini_rt *rt,
		t_calcul_color *info)
{
	int		i;
	t_vec2	inter;

	i = 0;
	inter.x = -1;
	inter.y = -1;
	while (i < bvh_node->nb_object)
	{
		info->i = bvh_node->index_object[i];
		if (info->i != info->j_obj)
		{
			inter = ft_choose_intersect(rt->object[info->i], ray);
			ft_inter_choice(info, inter);
			if (info->dist_obj != INFINITY
				&& rt->object[info->i].type != lights)
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_initialize_intersect_bvh(t_bvh_array *bvh, t_intersect_bvh *data)
{
	data->i = 0;
	data->bvh_node = &bvh->bvh[0];
	data->inter[0].x = -1;
	data->inter[0].y = -1;
}

void	ft_swap_bvh_2(t_intersect_bvh *data)
{
	t_bvh	*tmp;
	t_vec2	tmp_vec;

	if (data->inter[1].x > data->inter[2].x)
	{
		tmp_vec = data->inter[1];
		data->inter[1] = data->inter[2];
		data->inter[2] = tmp_vec;
		tmp = data->child[0];
		data->child[0] = data->child[1];
		data->child[1] = tmp;
	}
}

void	ft_check_child_box(t_ray ray, t_intersect_bvh *data, t_bvh_array *bvh)
{
	data->inter[1].x = -1;
	data->inter[1].y = -1;
	data->inter[2].x = -1;
	data->inter[2].y = -1;
	if (data->bvh_node->left >= 0)
	{
		data->child[0] = &bvh->bvh[data->bvh_node->left];
		data->inter[1] = ft_intersect_box(ray, data->child[0]->aabb);
	}
	if (data->bvh_node->right >= 0)
	{
		data->child[1] = &bvh->bvh[data->bvh_node->right];
		data->inter[2] = ft_intersect_box(ray, data->child[1]->aabb);
	}
}
