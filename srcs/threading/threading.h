/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:14:22 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/26 11:03:31 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADING_H
# define THREADING_H
# include "../mini_rt.h"

t_task	ft_create_task(int i);
t_task	ft_create_task_v(int i);
void	ft_init_task(t_mini_rt *rt);
void	ft_init_thread(t_mini_rt *rt);
void	ft_resize_task_arrays(t_mini_rt *rt);

#endif