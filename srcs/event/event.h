/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:04:07 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/10 10:37:19 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H
# include "../mini_rt.h"

typedef struct s_mini_rt	t_mini_rt;
typedef struct s_input		t_input;

typedef struct s_select_info
{
	float					dist_obj;
	int						ind_obj;
	int						i;
}							t_select_info;

typedef struct s_mouse_move_info
{
	float					rot_x;
	float					rot_y;
	int						x;
	int						y;
}							t_mouse_move_info;

//-----change_settings.c-----
void	ft_change_set(t_mini_rt *rt);

//-----change_info.c-----
void	ft_change_info(t_mini_rt *rt, int keycode);

//-----ft_press.c-----
int		ft_press(int keycode, t_mini_rt *rt);
int		ft_press_control(int keycode, t_mini_rt *rt);
int		ft_press_general(int keycode, t_mini_rt *rt);

//-----ft_press_classic.c-----
int		ft_press_classic(int keycode, t_mini_rt *rt);

//-----ft_press_classic_2.c-----
void	ft_esc(t_mini_rt *rt);
void	ft_enter_menu(t_mini_rt *rt);
void	ft_on_off_rot(t_mini_rt *rt);
void	ft_on_off_rot_obj(t_mini_rt *rt);

//-----ft_close.c-----
int		ft_close(t_mini_rt *rt);

//-----ft_release.c-----
int		ft_release(int keycode, t_mini_rt *rt);

//-----mouse_hook.c-----
int		ft_mouse_hook(int keycode, int x, int y, t_mini_rt *rt);
void	ft_select_general(t_mini_rt *rt, int x, int y);
void	ft_restart(t_mini_rt *rt);
void	ft_select_control(t_mini_rt *rt, int x, int y);

//-----mouse_moov.c-----
int		ft_mouse_move(t_mini_rt *rt);

//-----small_menu.c-----
void	ft_small_menu_2(t_mini_rt *rt);
void	ft_small_menu_3(t_mini_rt *rt);
void	ft_small_menu_4(t_mini_rt *rt);
void	ft_small_menu_5(t_mini_rt *rt);

#endif