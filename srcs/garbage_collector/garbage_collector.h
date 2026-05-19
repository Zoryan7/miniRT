/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:49:25 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 04:07:58 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include "../mini_rt.h"

/* garbage_collector */
void			*ft_gc_malloc(size_t size, size_t nbytes, t_garbage_type type);
t_garbage_list	*ft_gc_list(void);

/* free */
void			ft_free_gc(void);
void			ft_free_gc_type(t_garbage_type type);
void			*ft_add_to_gc(void *memory, t_garbage_type type);

#endif