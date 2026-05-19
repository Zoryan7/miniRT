/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:30:51 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:05:16 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../mini_rt.h"
# include "parsing_json/parsing_json.h"
# include "parsing_rt/parsing_rt.h"
# include "parsing_struct.h"

t_mini_rt		*ft_parsing(int ac, char **av);
int				ft_parse_file(char *file, t_parsing *parsing, t_mini_rt *rt,
					int type_file);
int				ft_parsing_file(char *map, t_mini_rt *rt, int file_type);

/* initialize */
t_mini_rt		*ft_initialize_mini_rt(void);
t_parsing		*ft_initialize_parsing(void);

/* initialize_2 */
char			**ft_initialize_json_maps(t_mini_rt *rt);
char			**ft_initialize_rt_maps(t_mini_rt *rt);
t_light_info	*ft_new_light(void);
t_object_info	*ft_new_object(void);
t_texture_info	*ft_new_texture(void);

/* parsing_utils */
t_vec			ft_light_sphere_color(t_light_info light, t_mini_rt *rt);
int				ft_add_lights_object(t_light_info *light, t_parsing *parsing,
					t_mini_rt *rt, int i);
t_light			*ft_add_lights(t_light_list light, t_parsing *parsing,
					t_mini_rt *rt);
t_object		*ft_add_objects(t_object_list object, int size_texture);
t_texture		*ft_add_textures(t_texture_list texture);
int				ft_verif_file_name(char *file);

/* parsing_utils_2 */
char			**ft_initialize_json_maps(t_mini_rt *rt);
char			**ft_initialize_rt_maps(t_mini_rt *rt);
t_object		*ft_join_object(t_object *obj, int size_obj, t_object *general,
					t_object *control);
char			*ft_get_next_line_parsing(int fd);

void			ft_add_back_texture(t_texture_info *new, t_parsing *parsing);
void			ft_add_back_light(t_light_info *new, t_parsing *parsing);

/* parsing_utils_3 */
int				ft_check_normalize(t_vec vec);
void			ft_add_map_gc(char **splited_maps);
int				ft_check_index_texture(t_object *dest, int size,
					int size_texture);

/* dict */
t_keycode_dict	*ft_create_dict(void);
t_keycode_dict	*ft_create_dict_2(t_keycode_dict *dict);
t_keycode_dict	*ft_create_dict_3(t_keycode_dict *dict);
t_keycode_dict	*ft_create_node_dict(char *name, int keycode);
void			ft_add_dict(t_keycode_dict **head, t_keycode_dict *node);

#endif