/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:37:14 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:06:30 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "parsing_struct.h"

void	ft_add_plane_object(t_object *dest, t_object_list object, int *i)
{
	while (object.head)
	{
		if (object.head->object.type == plane)
		{
			dest[*i] = object.head->object;
			*i += 1;
		}
		object.head = object.head->next;
	}
}

t_object	*ft_add_objects(t_object_list object, int size_texture)
{
	t_object	*dest;
	int			i;

	dest = ft_gc_malloc(object.size, sizeof(t_object), maps_type);
	if (!dest)
		return (NULL);
	i = 0;
	ft_add_plane_object(dest, object, &i);
	while (object.head)
	{
		if (object.head->object.type != plane)
		{
			dest[i] = object.head->object;
			i++;
		}
		object.head = object.head->next;
	}
	if (ft_check_index_texture(dest, object.size, size_texture))
		return (NULL);
	return (dest);
}

t_vec	ft_light_sphere_color(t_light_info light, t_mini_rt *rt)
{
	t_vec	color;
	t_vec	ambient_color;
	t_vec	light_color;
	t_vec	obj_color;

	obj_color = light.light.color;
	ambient_color.r = ft_minf(obj_color.r * rt->ambient.color.r
			* rt->ambient.brightness, 1.0);
	ambient_color.g = ft_minf(obj_color.g * rt->ambient.color.g
			* rt->ambient.brightness, 1.0);
	ambient_color.b = ft_minf(obj_color.b * rt->ambient.color.b
			* rt->ambient.brightness, 1.0);
	light_color.r = ft_minf(obj_color.r * light.light.brightness, 1.0);
	light_color.b = ft_minf(obj_color.b * light.light.brightness, 1.0);
	light_color.g = ft_minf(obj_color.g * light.light.brightness, 1.0);
	color.r = ft_minf(ambient_color.r + light_color.r, 1.0);
	color.g = ft_minf(ambient_color.g + light_color.g, 1.0);
	color.b = ft_minf(ambient_color.b + light_color.b, 1.0);
	color.t = 0.0;
	return (color);
}

int	ft_add_lights_object(t_light_info *light, t_parsing *parsing, t_mini_rt *rt,
		int i)
{
	t_object_info	*dest;

	dest = ft_new_object();
	if (!dest)
		return (1);
	dest->object.type = lights;
	dest->object.coord.x = light->light.coord.x;
	dest->object.coord.y = light->light.coord.y;
	dest->object.coord.z = light->light.coord.z;
	dest->object.color = ft_light_sphere_color(*light, rt);
	dest->object.specificites.lights.diameter = light->light.radius * 2;
	dest->object.specificites.lights.radius = light->light.radius;
	dest->object.id_texture = light->light.id_texture;
	dest->object.id_bump = light->light.id_bump;
	dest->object.specificites.lights.index = i;
	ft_add_back_object(dest, parsing);
	return (0);
}

t_light	*ft_add_lights(t_light_list light, t_parsing *parsing, t_mini_rt *rt)
{
	t_light	*dest;
	int		i;

	dest = ft_gc_malloc(light.size, sizeof(t_light), maps_type);
	if (!dest)
		return (NULL);
	i = 0;
	while (light.head)
	{
		if (ft_add_lights_object(light.head, parsing, rt, i))
			return (NULL);
		dest[i] = light.head->light;
		light.head = light.head->next;
		i++;
	}
	return (dest);
}
