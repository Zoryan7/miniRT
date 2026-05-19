/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 13:38:32 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 11:47:43 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"

void	ft_affect_index_child(t_bvh *parent, t_bvh *left, t_bvh *right,
		t_bvh_array *array)
{
	if (left)
	{
		parent->left = array->nb_bvh;
		array->bvh[array->nb_bvh] = *left;
		array->nb_bvh++;
	}
	if (right)
	{
		parent->right = array->nb_bvh;
		array->bvh[array->nb_bvh] = *right;
		array->nb_bvh++;
	}
}

int	ft_next_parent(t_create_bvh *data, t_bvh_array *array)
{
	if (data->left && data->left->nb_object > 1)
	{
		if (data->right && data->right->nb_object > 1)
			data->stack[data->i++] = data->parent->right;
		data->parent = &array->bvh[data->parent->left];
	}
	else if (data->right && data->right->nb_object > 1)
	{
		data->parent = &array->bvh[data->parent->right];
	}
	else
	{
		if (data->i == 0)
			return (1);
		data->parent = &array->bvh[data->stack[--data->i]];
	}
	return (0);
}

int	ft_affect_child(t_create_bvh *data, t_bvh_array *array, t_mini_rt *rt)
{
	data->left = ft_new_bvh_node(data->parent->nb_object);
	data->right = ft_new_bvh_node(data->parent->nb_object);
	if (!data->left || !data->right)
		return (1);
	if (ft_affect_to_each_object(data->parent, data->left, data->right, rt))
	{
		if (data->i == 0)
			return (1);
		data->parent = &array->bvh[data->stack[--data->i]];
		return (2);
	}
	ft_split_bvh_2(&data->left, &data->right, rt, data->parent->lvl);
	ft_affect_index_child(data->parent, data->left, data->right, array);
	return (0);
}

int	ft_split_bvh(t_bvh_array *array, t_mini_rt *rt)
{
	t_create_bvh	data;
	int				i;

	data.i = 0;
	data.parent = &array->bvh[0];
	while (1)
	{
		if (data.parent->nb_object == 1 || data.parent->lvl == 21)
		{
			if (data.i == 0)
				return (0);
			data.parent = &array->bvh[data.stack[--data.i]];
			continue ;
		}
		i = ft_affect_child(&data, array, rt);
		if (i == 1)
			return (0);
		else if (i == 2)
			continue ;
		if (ft_next_parent(&data, array))
			return (0);
	}
	return (0);
}

t_bvh_array	*ft_bvh(t_mini_rt *rt)
{
	t_bvh_array	*dest;

	dest = ft_global_node(rt);
	if (!dest)
		return (NULL);
	if (ft_split_bvh(dest, rt))
		return (NULL);
	return (dest);
}
