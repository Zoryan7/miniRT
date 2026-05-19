/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_json.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:12:53 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:32:15 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_JSON_H
# define PARSING_JSON_H
# include "../../mini_rt.h"
# include "../parsing.h"
# include "../parsing_struct.h"

/* initialization */
t_object_info	*ft_new_object_json(int type);
void			ft_new_object_sphere(t_object_info *dest);
void			ft_new_object_rounded_box(t_object_info *dest);
void			ft_new_object_box(t_object_info *dest);

/* parse_file */
int				ft_parse_file_json(char *file, t_parsing *parsing,
					t_mini_rt *rt);

/* parse_value */
int				ft_parse_coordinates(char *value, t_vec *coord);
int				ft_parse_normal(char *value, t_vec *normal);
int				ft_parse_fov(char *value, unsigned char *fov, int *nb_fov);
int				ft_parse_single_float(char *value, float *dest, char *name);
int				ft_parse_color(char *value, t_vec *color);
int				ft_parse_ratio(char *value, float *ratio, char *name);

/* parse_object_json */
int				ft_add_value_to_key_object(t_texture_list *textures,
					t_object_info *dest, char *key, char *value);
int				ft_parse_sphere_json(t_parsing *parsing, int fd);
int				ft_parse_plane_json(t_parsing *parsing, int fd);
int				ft_parse_cylinder_json(t_parsing *parsing, int fd);
int				ft_parse_cone_json(t_parsing *parsing, int fd);
int				ft_parse_rounded_box_json(t_parsing *parsing, int fd);
int				ft_parse_box_json(t_parsing *parsing, int fd);
int				ft_parse_triangle_json(t_parsing *parsing, int fd);

/* parse_rt_json */
int				ft_parse_camera_json(t_mini_rt *rt, t_parsing *parsing, int fd);
int				ft_parse_light_json(t_parsing *parsing, int fd);
int				ft_parse_ambient_json(t_mini_rt *rt, t_parsing *parsing,
					int fd);

/* parse_texture_json */
int				ft_parse_textures_json(t_texture_list *textures, char *line,
					int *dest, char *name);

/* parsing_json_utils */
int				ft_split_value_key(char *line, char **key, char **value);
int				ft_check_in_out_object(char *line, int pos);
int				ft_cmp_key(char *key, char *cmp, int pos);
int				ft_ratio_positive(float *dest, char *name, char *value);

/*	check_value */
int				ft_check_good_values_object(t_object_info *object);
int				ft_check_good_values_sphere(t_object_info *object);
int				ft_check_good_values_plane(t_object_info *object);
int				ft_check_good_values_cylinder(t_object_info *object);
int				ft_check_good_values_cone(t_object_info *object);
int				ft_check_good_values_rounded_box(t_object_info *object);

#endif