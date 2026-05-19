/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:51:12 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:08:40 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "parsing_struct.h"

int	ft_parse_file(char *file, t_parsing *parsing, t_mini_rt *rt, int type_file)
{
	if (type_file == 1)
		return (ft_parse_file_json(file, parsing, rt));
	return (ft_parse_file_rt(file, parsing, rt));
}

t_mini_rt	*ft_parsing(int ac, char **av)
{
	t_mini_rt	*rt;
	int			file_type;

	if (ac != 2)
		return (ft_put_error("Error : invalid number of arguments\n", 2), NULL);
	file_type = ft_verif_file_name(av[1]);
	if (file_type == -1)
		return (ft_put_error("Error : invalid type of file\n", 2), NULL);
	rt = ft_initialize_mini_rt();
	if (!rt)
		return (ft_put_error("Error : problem with initialize\n", 2), NULL);
	if (ft_parsing_file(av[1], rt, file_type))
		return (NULL);
	rt->move_on = 0;
	rt->nb_img = 0;
	rt->selec_button = __INT_MAX__;
	rt->info.maps_rt = ft_initialize_rt_maps(rt);
	rt->info.maps_json = ft_initialize_json_maps(rt);
	rt->bvh = ft_bvh(rt);
	return (rt);
}

int	ft_chain_to_array_parsing(t_parsing *parsing, t_mini_rt *rt)
{
	rt->light = ft_add_lights(parsing->light, parsing, rt);
	rt->object = ft_add_objects(parsing->object, parsing->texture.size);
	if (!rt->light || !rt->object)
		return (1);
	rt->object = ft_join_object(rt->object, parsing->object.size,
			rt->general_page, rt->control_page);
	rt->texture = ft_add_textures(parsing->texture);
	rt->size_light = parsing->light.size;
	rt->size_object = parsing->object.size;
	rt->size_texture = parsing->texture.size;
	return (0);
}

void	ft_reboot_rt(t_mini_rt *rt)
{
	rt->camera.coord.w = 0;
	rt->camera.forward.w = 0;
	rt->ambient.color.t = 0;
	rt->ambient.brightness = -1;
}

int	ft_parsing_file(char *map, t_mini_rt *rt, int file_type)
{
	t_parsing	*parsing;
	char		*dest;

	parsing = ft_initialize_parsing();
	if (ft_parse_file("maps/rt/general_page.rt", parsing, rt, 0))
		return (ft_put_error("Error : general page not found\n", 2), 1);
	rt->general_page = ft_add_objects(parsing->object, parsing->texture.size);
	parsing = ft_initialize_parsing();
	ft_reboot_rt(rt);
	if (ft_parse_file("maps/rt/control_page.rt", parsing, rt, 0))
		return (ft_put_error("Error : control page not found\n", 2), 1);
	(rt->control_page = ft_add_objects(parsing->object, parsing->texture.size));
	parsing = ft_initialize_parsing();
	ft_reboot_rt(rt);
	if (ft_parse_file(map, parsing, rt, file_type))
		return (ft_put_error("Error : problem with initialize\n", 2), 1);
	if (ft_chain_to_array_parsing(parsing, rt))
		return (ft_put_error("Error : invalid texture or bump map\n", 2), 1);
	dest = ft_strdup(map);
	ft_add_to_gc(dest, rt_type);
	rt->info.map = dest;
	return (0);
}
