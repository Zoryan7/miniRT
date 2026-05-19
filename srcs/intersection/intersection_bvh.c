/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_bvh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:27:42 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 11:09:53 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int	ft_next_bvh_node(t_intersect_bvh *data, t_bvh_array *bvh,
		t_calcul_color *info)
{
	if (data->inter[1].y >= 0 && data->inter[1].x <= data->inter[1].y
		&& data->inter[1].x <= info->dist_obj)
	{
		info->touch++;
		data->bvh_node = data->child[0];
		if (data->inter[2].y > 0 && data->inter[2].x <= data->inter[2].y
			&& data->inter[2].x <= info->dist_obj)
			data->stack[data->i++] = (int)(data->child[1] - bvh->bvh);
	}
	else if (data->inter[2].y >= 0 && data->inter[2].x <= data->inter[2].y
		&& data->inter[2].x <= info->dist_obj)
	{
		info->touch++;
		data->bvh_node = data->child[1];
	}
	else
	{
		if (data->i == 0)
			return (1);
		data->bvh_node = &bvh->bvh[data->stack[--data->i]];
	}
	return (0);
}

t_vec2	ft_intersect_bvh(t_ray ray, t_bvh_array *bvh, t_mini_rt *rt,
		t_calcul_color *info)
{
	t_intersect_bvh	data;

	ft_initialize_intersect_bvh(bvh, &data);
	while (1)
	{
		if (data.bvh_node->left == -1)
		{
			data.inter[0] = ft_leaf_bvh(ray, data.bvh_node, rt, info);
			if (data.i == 0)
				return (data.inter[0]);
			else
			{
				data.bvh_node = &bvh->bvh[data.stack[--data.i]];
				continue ;
			}
		}
		ft_check_child_box(ray, &data, bvh);
		ft_swap_bvh_2(&data);
		if (ft_next_bvh_node(&data, bvh, info))
			return (data.inter[0]);
	}
	return (data.inter[0]);
}

int	ft_intersect_bvh_light(t_ray ray, t_bvh_array *bvh, t_mini_rt *rt,
		t_calcul_color *info)
{
	t_intersect_bvh	data;

	ft_initialize_intersect_bvh(bvh, &data);
	while (1)
	{
		if (data.bvh_node->left == -1)
		{
			if (ft_leaf_bvh_light(ray, data.bvh_node, rt, info))
				return (1);
			if (data.i == 0)
				return (0);
			else
			{
				data.bvh_node = &bvh->bvh[data.stack[--data.i]];
				continue ;
			}
		}
		ft_check_child_box(ray, &data, bvh);
		ft_swap_bvh_2(&data);
		if (ft_next_bvh_node(&data, bvh, info))
			return (0);
	}
	return (0);
}
