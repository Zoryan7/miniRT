/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:48:02 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 03:47:44 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_RT_H
# define PARSING_RT_H
# include "../../mini_rt.h"
# include "../parsing.h"
# include "../parsing_struct.h"

/* parse_file */

int				ft_parse_file_rt(char *file, t_parsing *parsing, t_mini_rt *rt);

/* parse_ambient */
int				ft_parse_ambient(char *line, t_mini_rt *rt, t_parsing *parsing);

/* parse_camera */
int				ft_parse_camera(char *line, t_mini_rt *rt, t_parsing *parsing);

/* parse_light */
int				ft_parse_light(char *line, t_parsing *parsing);

/* parse_object */
int				ft_parse_object(char *line, t_parsing *parsing, int object);
int				ft_parse_texture_bump(char *line, int *id_texture, int *id_bump,
					int *i);

/* parse_object_specificities */
int				ft_parse_plane_specificities(char *line, t_object_info *object,
					int *i);
int				ft_parse_cone_specificities(char *line, t_object_info *object,
					int *i);
int				ft_parse_cylinder_specificities(char *line,
					t_object_info *object, int *i);
int				ft_parse_sphere_specificities(char *line, t_object_info *object,
					int *i);
int				ft_parse_r_box_specificities(char *line, t_object_info *object,
					int *i);
int				ft_parse_box_specificities(char *line, t_object_info *object,
					int *i);
int				ft_parse_triangle_specificities(char *line,
					t_object_info *object, int *i);

/* parse_object_utils */
int				ft_parse_coord_object(char *line, t_object_info *object,
					int *i);
void			ft_add_back_object(t_object_info *new, t_parsing *parsing);
t_object_info	*ft_new_object(void);
int				ft_parse_color_object(char *line, t_object_info *object,
					int *i);
float			ft_diameter(t_object_info *object);
float			ft_radius(t_object_info *object);

/* parse_texture */
int				ft_parse_texture_rt(char **line, int fd, t_parsing *parsing);

/* parsing_colors */
int				ft_recup_color(char *color, char *line, int *i, int pos);
int				ft_char_to_color(float *dest, char *color);
int				ft_char_to_color_spec(float *dest, char *color);
int				ft_char_to_color_fov(unsigned char *dest, char *color);

/* parsing_cord */
int				ft_recup_float(char *line, float *dest, int *i, int pos);

/* parsing_brightness */
int				ft_parse_brightness_light(char *line, t_light_info *light,
					int *i);
int				ft_parse_brightness_ambient(char *line, t_mini_rt *rt, int *i);

/* parsing_utils */
int				ft_verif_dot(char *src, int nb);
int				ft_skip_space(int *i, char *line, int pos);
int				ft_triple_recup_float_1(char *line, t_vec *vec, int *i);
int				ft_triple_recup_float_2(char *line, t_vec *vec, int *i);
int				ft_triple_recup_float_3(char *line, t_vec *vec, int *i);

#endif