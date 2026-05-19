/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:30:51 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:05:42 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_STRUCT_H
# define PARSING_STRUCT_H
# include "../mini_rt.h"
# include "parsing.h"

typedef struct s_object_info
{
	t_object				object;
	struct s_object_info	*next;
}							t_object_info;

typedef struct s_object_list
{
	struct s_object_info	*head;
	struct s_object_info	*tail;
	int						size;
}							t_object_list;

typedef struct s_light_info
{
	t_light					light;
	struct s_light_info		*next;
}							t_light_info;

typedef struct s_light_list
{
	struct s_light_info		*head;
	struct s_light_info		*tail;
	int						size;
}							t_light_list;

typedef struct s_texture_info
{
	t_texture				texture;
	struct s_texture_info	*next;
}							t_texture_info;

typedef struct s_texture_list
{
	struct s_texture_info	*head;
	struct s_texture_info	*tail;
	int						size;
}							t_texture_list;

typedef struct s_parsing
{
	t_light_list			light;
	t_object_list			object;
	t_texture_list			texture;
	int						ambient;
	int						camera;
	int						fov;
	int						is_texture;
}							t_parsing;

#endif