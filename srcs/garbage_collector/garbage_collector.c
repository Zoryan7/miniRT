/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:48:06 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 22:39:00 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

t_garbage_list	*ft_gc_list(void)
{
	static t_garbage_list	*lst = NULL;

	if (!lst)
	{
		lst = malloc(sizeof(t_garbage_list));
		if (!lst)
			return (NULL);
		lst->head = NULL;
		lst->tail = NULL;
		lst->size = 0;
	}
	return (lst);
}

t_garbage	*ft_new_node_gc(void *memory, t_garbage_type type)
{
	t_garbage	*dest;

	dest = malloc(sizeof(t_garbage));
	if (!dest)
		return (NULL);
	dest->memory = memory;
	dest->type = type;
	dest->next = NULL;
	return (dest);
}

void	*ft_gc_malloc(size_t size, size_t nbytes, t_garbage_type type)
{
	t_garbage_list	*lst;
	t_garbage		*new;
	void			*memory;

	memory = ft_calloc(nbytes, size);
	if (!memory)
		return (NULL);
	new = ft_new_node_gc(memory, type);
	if (!new)
		return (free(memory), NULL);
	lst = ft_gc_list();
	if (!lst->head)
	{
		lst->head = new;
		lst->tail = new;
	}
	else
	{
		lst->tail->next = new;
		lst->tail = new;
	}
	return (memory);
}

void	*ft_add_to_gc(void *memory, t_garbage_type type)
{
	t_garbage_list	*lst;
	t_garbage		*new;

	new = ft_new_node_gc(memory, type);
	if (!new)
		return (free(memory), NULL);
	lst = ft_gc_list();
	if (!lst->head)
	{
		lst->head = new;
		lst->tail = new;
	}
	else
	{
		lst->tail->next = new;
		lst->tail = new;
	}
	return (memory);
}
