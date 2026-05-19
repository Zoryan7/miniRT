/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_page_txt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:51:10 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/27 14:10:16 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	ft_control_page2(t_mini_rt *rt, char *input, float pos_x,
		float pos_y)
{
	char	str[2];

	str[1] = 0;
	input = ft_atoa(rt->code_input.rot_on_off, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (430 - (ft_strlen(input) * 5)) * pos_x, 350
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 505 * pos_x, 350 * pos_y, 0xFFFFFF,
		"Rot Object");
	input = ft_atoa(rt->code_input.rot_obj, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (644 - (ft_strlen(input) * 4)) * pos_x, 350
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 280 * pos_x, 415 * pos_y, 0xFFFFFF,
		"Open Menu");
	input = ft_atoa(rt->code_input.menu, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (430 - (ft_strlen(input) * 5)) * pos_x, 415
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 505 * pos_x, 415 * pos_y, 0xFFFFFF,
		"Blur");
	input = ft_atoa(rt->code_input.blur, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (644 - (ft_strlen(input) * 4)) * pos_x, 415
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 122 * pos_x, 60 * pos_y, 0xDDDDDD,
		"General");
	mlx_string_put(rt->mlx, rt->win, 122 * pos_x, 94 * pos_y, 0xFFFFFF,
		"Control");
}

static void	ft_control_page1(t_mini_rt *rt, char *input, float pos_x,
		float pos_y)
{
	char	str[2];

	str[1] = 0;
	input = ft_atoa(rt->code_input.backward, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (430 - (ft_strlen(input) * 5)) * pos_x, 220
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 505 * pos_x, 220 * pos_y, 0xFFFFFF,
		"Rigth");
	input = ft_atoa(rt->code_input.right, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (644 - (ft_strlen(input) * 4)) * pos_x, 220
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 280 * pos_x, 285 * pos_y, 0xFFFFFF, "Up");
	input = ft_atoa(rt->code_input.up, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (430 - (ft_strlen(input) * 5)) * pos_x, 285
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 505 * pos_x, 285 * pos_y, 0xFFFFFF,
		"Down");
	input = ft_atoa(rt->code_input.down, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (644 - (ft_strlen(input) * 4)) * pos_x, 285
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 280 * pos_x, 350 * pos_y, 0xFFFFFF,
		"On/Off Rot");
	mlx_string_put(rt->mlx, rt->win, 138 * pos_x, 128 * pos_y, 0xDDDDDD,
		"Exit");
	ft_control_page2(rt, input, pos_x, pos_y);
}

void	ft_control_page(t_mini_rt *rt)
{
	char	str[2];
	char	*input;
	float	pos_x;
	float	pos_y;

	pos_x = (float)rt->info.width / 960.0f;
	pos_y = (float)rt->info.height / 480.0f;
	str[1] = 0;
	mlx_set_font(rt->mlx, rt->win, "10x20");
	mlx_string_put(rt->mlx, rt->win, 270 * pos_x, 60 * pos_y, 0xFFFFFF,
		"Control");
	mlx_string_put(rt->mlx, rt->win, 280 * pos_x, 155 * pos_y, 0xFFFFFF,
		"Forward");
	input = ft_atoa(rt->code_input.forward, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (430 - (ft_strlen(input) * 5)) * pos_x, 155
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 505 * pos_x, 155 * pos_y, 0xFFFFFF,
		"Left");
	input = ft_atoa(rt->code_input.left, str, &rt->keycode_dict);
	mlx_string_put(rt->mlx, rt->win, (644 - (ft_strlen(input) * 4)) * pos_x, 155
		* pos_y, 0xFFFFFF, input);
	mlx_string_put(rt->mlx, rt->win, 280 * pos_x, 220 * pos_y, 0xFFFFFF,
		"Backward");
	ft_control_page1(rt, input, pos_x, pos_y);
}
