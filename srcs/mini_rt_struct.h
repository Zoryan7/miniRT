/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:06:46 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 09:06:32 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_STRUCT_H
# define MINI_RT_STRUCT_H
# include "mini_rt.h"
# define TOTAL_SIZE 3686400

typedef struct s_all_axis
{
	t_vec	*axis_x;
	t_vec	*axis_y;
	t_vec	*axis_z;
}	t_all_axis;

typedef enum e_garbage_type
{
	parsing_type,
	rt_type,
	maps_type,
	keycode_type,
	bvh_type,
}							t_garbage_type;

typedef struct s_garbage
{
	void					*memory;
	t_garbage_type			type;
	struct s_garbage		*next;
}							t_garbage;

typedef struct s_garbage_list
{
	t_garbage				*head;
	t_garbage				*tail;
	int						size;
}							t_garbage_list;

typedef struct s_input
{
	unsigned char			forward;
	unsigned char			backward;
	unsigned char			left;
	unsigned char			right;
	unsigned char			up;
	unsigned char			down;
}							t_input;

typedef struct s_code_input
{
	int						forward;
	int						backward;
	int						left;
	int						right;
	int						up;
	int						down;
	int						menu;
	int						quit;
	int						rot_on_off;
	int						rot_obj;
	int						blur;
	int						normal;
	int						opti;
	int						bvh;
}							t_code_input;

typedef struct s_aabb
{
	t_vec					min;
	t_vec					max;
}							t_aabb;

typedef enum e_object_type
{
	cylinder,
	sphere,
	cone,
	plane,
	rounded_box,
	box,
	triangle,
	lights
}							t_object_type;

typedef struct s_cylindre
{
	float					height;
	float					diameter;
	float					radius;
}							t_cylindre;

typedef struct s_sphere
{
	float					diameter;
	float					radius;
}							t_sphere;

typedef struct s_cone
{
	float					height;
	float					diameter;
	float					radius;
	t_vec					apex;
}							t_cone;

typedef struct s_rounded_box
{
	t_vec					size;
	t_vec					init_coord;
	float					radius;
}							t_rounded_box;

typedef struct s_triangle
{
	t_vec					a;
	t_vec					b;
	t_vec					c;
	t_vec					ac;
	t_vec					ab;
	t_vec					a_normal;
	t_vec					b_normal;
	t_vec					c_normal;
	t_vec2					a_uv;
	t_vec2					b_uv;
	t_vec2					c_uv;
	int						has_vertex_normal;
	int						has_vertex_uv;
}							t_triangle;

typedef struct s_lights
{
	int						index;
	float					diameter;
	float					radius;
}							t_lights;

typedef struct s_box
{
	struct s_aabb			aabb;
}							t_box;

typedef union u_specificities
{
	struct s_lights			lights;
	struct s_cylindre		cylinder;
	struct s_sphere			sphere;
	struct s_cone			cone;
	struct s_rounded_box	rounded_box;
	struct s_box			box;
	struct s_triangle		triangle;
}							t_specificities;

typedef struct s_img
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
}							t_img;

typedef struct s_texture
{
	t_img					img;
	char					*name;
	int						width;
	int						height;
}							t_texture;

typedef struct s_object
{
	t_vec					coord;
	t_vec					vec;
	t_vec					init_vec;
	t_vec					up_vec;
	t_vec					init_up_vec;
	t_vec					color;
	float					randomless;
	float					reflection;
	float					transparency;
	float					refraction_indice;
	float					rot_x;
	float					rot_y;
	int						id_bump;
	int						id_texture;
	union u_specificities	specificites;
	enum e_object_type		type;
}							t_object;

typedef struct s_light
{
	t_vec					coord;
	t_vec					color;
	float					brightness;
	float					radius;
	int						id_bump;
	int						id_texture;
	int						type_object;
}							t_light;

typedef struct s_camera
{
	t_vec					coord;
	t_vec					up;
	t_vec					init_forward;
	t_vec					forward;
	t_vec					right;
	t_vec					view_u;
	t_vec					view_v;
	t_vec					view_origin;
	t_vec					first_pixel;
	t_vec					delta_u;
	t_vec					delta_v;
	float					view_width;
	float					view_height;
	unsigned char			focal_lenght;
	unsigned char			fov;
	float					eta;
	float					rot_x;
	float					rot_y;
	float					rand_x;
	float					rand_y;
}							t_camera;

typedef struct s_ambient
{
	t_vec					color;
	t_vec					color_2;
	float					brightness;
}							t_ambient;

typedef struct s_task
{
	int						y;
	int						x;
}							t_task;

typedef struct s_sync
{
	pthread_mutex_t			mutex;
	pthread_cond_t			cond;
	int						pause;
}							t_sync;

typedef struct s_bvh
{
	t_aabb					aabb;
	int						lvl;
	int						nb_object;
	int						*index_object;
	int						left;
	int						right;
}							t_bvh;

typedef struct s_bvh_array
{
	t_bvh					*bvh;
	int						nb_bvh;
}							t_bvh_array;

typedef struct s_calcul_color
{
	float					dist_obj;
	int						ind_obj;
	int						i;
	int						j_obj;
	int						touch;
	unsigned char			out;
	t_task					task;
}							t_calcul_color;

typedef struct s_keycode_dict
{
	char					*name;
	int						keycode;
	struct s_keycode_dict	*next;
}							t_keycode_dict;

typedef struct s_info_win
{
	int						width;
	int						height;
	int						new_width;
	int						new_height;
	int						width_mid;
	int						height_mid;
	int						bounce;
	float					sensi;
	float					speed;
	float					exposure;
	float					saturation;
	float					white;
	char					*map;
	char					*new_map;
	char					**maps_rt;
	int						nb_maps_rt;
	char					**maps_json;
	int						nb_maps_json;
	int						scroll;
	char					*new_fov;
	char					*new_sensi;
	char					*new_speed;
	char					*new_bounce;
}							t_info_win;

typedef struct s_mini_rt
{
	struct s_camera			camera;
	struct s_ambient		ambient;
	struct s_light			*light;
	struct s_object			*object;
	struct s_texture		*texture;
	struct s_bvh_array		*bvh;
	struct s_img			img;
	struct s_input			input;
	struct s_code_input		code_input;
	struct s_info_win		info;
	struct s_task			*task;
	struct s_task			*task_v;
	struct s_sync			*sync;
	struct s_keycode_dict	*keycode_dict;
	struct s_object			*control_page;
	struct s_object			*general_page;
	pthread_t				*thread;
	_Atomic int				cur_task;
	_Atomic int				done_task;
	_Atomic int				end;
	_Atomic unsigned char	page;
	_Atomic unsigned char	blur_done;
	_Atomic int				nb_img;
	t_vec					last_img[TOTAL_SIZE];
	int						first_hit[TOTAL_SIZE];
	int						size_light;
	int						size_object;
	int						size_texture;
	int						selec;
	int						selec_button;
	unsigned char			rot_on;
	unsigned char			rot_obj;
	unsigned char			move_on;
	unsigned char			bvh_on;
	unsigned char			normal_on;
	unsigned char			opti_on;
	unsigned char			tone_on;
	void					*mlx;
	void					*win;
}							t_mini_rt;

typedef struct s_ray
{
	t_vec					origin;
	t_vec					destination;
	t_vec					direction;
	t_vec					r_direction;
	t_vec					normal;
	float					eta;
}							t_ray;

#endif