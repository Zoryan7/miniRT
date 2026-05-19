/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:30:02 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/27 14:19:43 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "../mini_rt.h"

typedef struct s_mini_rt	t_mini_rt;

void	ft_gui(t_mini_rt *rt, unsigned long elapsed);
void	ft_put_pixel(t_mini_rt *rt, int x, int y, t_vec color);
void	ft_crosshair(t_mini_rt *rt);
void	ft_control_page(t_mini_rt *rt);
void	ft_general_page(t_mini_rt *rt);
char	*ft_atoa(int n, char *dst, t_keycode_dict **dict);
char	*ft_recup_name(char *map);

void	ft_subpage_res(t_mini_rt *rt, float pos_x, float pos_y);
void	ft_subpage_map(t_mini_rt *rt, float pos_x, float pos_y);

#endif