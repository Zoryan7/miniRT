/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:42:54 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 04:34:22 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	ft_free_gc(void)
{
	t_garbage_list	*lst;
	t_garbage		*temp;
	t_garbage		*old_temp;

	lst = ft_gc_list();
	temp = lst->head;
	while (temp)
	{
		old_temp = temp;
		temp = temp->next;
		free(old_temp->memory);
		free(old_temp);
	}
	free(lst);
	lst = NULL;
}

static void	ft_affect_temp_gc(t_garbage **temp)
{
	temp[0] = temp[1];
	temp[1] = temp[1]->next;
}

void	ft_free_gc_type(t_garbage_type type)
{
	t_garbage_list	*lst;
	t_garbage		*temp[3];

	lst = ft_gc_list();
	temp[1] = lst->head;
	temp[0] = NULL;
	while (temp[1])
	{
		if (temp[1]->type == type)
		{
			temp[2] = temp[1]->next;
			if (temp[1] == lst->tail)
				lst->tail = temp[0];
			(free(temp[1]->memory), free(temp[1]));
			if (temp[0])
				temp[0]->next = temp[2];
			else
				lst->head = temp[2];
			temp[1] = temp[2];
		}
		else
			ft_affect_temp_gc(temp);
	}
	if (!lst->head)
		lst->tail = NULL;
}
