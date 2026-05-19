/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:04:37 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 04:28:13 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_initialize_input(t_mini_rt *dest)
{
	dest->input.forward = 0;
	dest->input.backward = 0;
	dest->input.left = 0;
	dest->input.right = 0;
	dest->input.up = 0;
	dest->input.down = 0;
	dest->code_input.forward = 119;
	dest->code_input.left = 97;
	dest->code_input.backward = 115;
	dest->code_input.right = 100;
	dest->code_input.up = 32;
	dest->code_input.down = 65507;
	dest->code_input.menu = 109;
	dest->code_input.quit = 65307;
	dest->code_input.rot_on_off = 117;
	dest->code_input.rot_obj = 114;
	dest->code_input.blur = 120;
	dest->code_input.bvh = 65436;
	dest->code_input.normal = 65433;
	dest->code_input.opti = 65435;
}

void	ft_initialize_info(t_mini_rt *dest)
{
	dest->info.new_width = 0;
	dest->info.new_height = 0;
	dest->info.new_map = NULL;
	dest->info.width = 960;
	dest->info.height = 480;
	dest->info.width_mid = dest->info.width * 0.5;
	dest->info.height_mid = dest->info.height * 0.5;
	dest->info.bounce = 10;
	dest->info.speed = 10.0f;
	dest->info.sensi = 0.2f;
	dest->info.exposure = 1.0f;
	dest->info.saturation = 1.0f;
	dest->info.white = 4.0f;
	dest->info.scroll = 0;
	dest->info.new_bounce = NULL;
	dest->info.new_sensi = NULL;
	dest->info.new_speed = NULL;
	dest->info.new_fov = NULL;
}

void	ft_initialize_camera(t_mini_rt *dest)
{
	dest->camera.coord.x = 0;
	dest->camera.coord.y = 0;
	dest->camera.coord.z = 0;
	dest->camera.coord.w = 0;
	dest->camera.fov = 200;
	dest->camera.forward.w = 0;
	dest->camera.rot_x = 0;
	dest->camera.rot_y = 0;
}

t_mini_rt	*ft_initialize_mini_rt(void)
{
	t_mini_rt	*dest;

	dest = ft_gc_malloc(1, sizeof(t_mini_rt), rt_type);
	if (!dest)
		return (NULL);
	dest->rot_on = 1;
	dest->rot_obj = 0;
	dest->light = NULL;
	dest->object = NULL;
	dest->selec = __INT_MAX__;
	dest->keycode_dict = ft_create_dict();
	dest->ambient.brightness = -1;
	dest->ambient.color.b = 0;
	dest->ambient.color.g = 0;
	dest->ambient.color.r = 0;
	dest->page = 0;
	dest->bvh_on = 0;
	dest->opti_on = 0;
	dest->tone_on = 0;
	dest->normal_on = 0;
	ft_initialize_camera(dest);
	ft_initialize_input(dest);
	ft_initialize_info(dest);
	return (dest);
}

t_parsing	*ft_initialize_parsing(void)
{
	t_parsing	*dest;

	dest = ft_gc_malloc(1, sizeof(t_parsing), parsing_type);
	if (!dest)
		return (NULL);
	dest->light.head = NULL;
	dest->light.tail = NULL;
	dest->light.size = 0;
	dest->object.head = NULL;
	dest->object.tail = NULL;
	dest->object.size = 0;
	dest->texture.head = NULL;
	dest->texture.tail = NULL;
	dest->texture.size = 0;
	dest->ambient = 0;
	dest->camera = 0;
	dest->fov = 0;
	dest->is_texture = 0;
	return (dest);
}
