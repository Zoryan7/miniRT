/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:39:12 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 05:39:36 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "../mini_rt.h"
# define POINT_IN_EPS 0.001f

typedef struct s_info_cone_point
{
	t_vec			axis;
	t_vec			diff;
	t_vec			mid;
	float			proj;
	float			radial2;
	float			limit_r;
	float			height;
}					t_info_cone_point;

typedef struct s_info_get_pixel
{
	float			uf;
	float			vf;
	int				x;
	int				y;
	float			dx;
	float			dy;
	int				x1;
	int				y1;
	t_vec			c1;
	t_vec			c2;
	t_vec			c3;
	t_vec			c4;
	t_vec			c5;
	t_vec			c6;
}					t_info_get_pixel;

typedef struct s_bump_info
{
	t_vec			hit_point;
	t_vec			pix_color;
	t_vec			bump_color;
	t_vec			tangent;
	t_vec			bitangent;
	t_vec			truc;
	t_vec			new;
	t_vec2			uv;
}					t_bump_info;

typedef struct s_info_light
{
	t_ray			shadow;
	t_vec2			inter;
	float			l;
	t_calcul_color	info;
	float			dist_light;
	t_vec			point_light;
	t_vec			hit_point;
	float			attenuation;
}					t_info_light;

typedef struct s_info_final_color
{
	float	intensity;
	t_vec	obj_color;
	t_vec	a_color;
	t_vec	diffuse_color;
	t_vec	final_color;
	int		rand;
}	t_info_final_color;

//-----light.c-----
float				ft_light(t_mini_rt *rt, t_calcul_color inf, t_ray ray,
						int rand);

//-----menu_1.c-----
void				ft_horizontal_blur_thread(t_mini_rt *rt, float *gauss_tab,
						t_task task, char *tmp);
void				ft_vertical_blur_thread(t_mini_rt *rt, float *gauss_tab,
						t_task task, char *tmp);
void				ft_horizontal_task(t_mini_rt *rt, t_task task,
						float *gauss_tab);
void				ft_vertical_task(t_mini_rt *rt, t_task task,
						float *gauss_tab);

//-----moov.c-----
void				ft_moov(t_mini_rt *rt, unsigned long elapsed);
void				ft_rotate(t_mini_rt *rt, t_vec rot);
void				ft_rotate_obj(t_mini_rt *rt, t_vec rot);
void				ft_has_to_moov(t_mini_rt *rt, t_vec *move);

//-----moov_2.c-----
void				ft_moov_obj(t_mini_rt *rt, unsigned long elapsed);
void				ft_moov_obj_obj(t_mini_rt *rt, float speed, t_vec move);
void				ft_moov_obj_light(t_mini_rt *rt, float speed, t_vec move);
void				ft_moov_obj_triangle(t_mini_rt *rt, float speed,
						t_vec move);
void				ft_moov_obj_cone(t_mini_rt *rt, float speed, t_vec move);

//-----multi_threading.c-----
void				*ft_routine(void *arg);
void				ft_release_thread(t_mini_rt *rt);
void				ft_block_thread(t_mini_rt *rt);

//-----render_utils.c-----
float				*ft_gauss(void);
float				ft_clampf(float a, float min, float max);
float				ft_rand(void);

//-----get_pixel.c-----
unsigned int		ft_get_pixel(char *addr, int line_length, int x, int y);
t_vec				ft_get_pixel_2(t_mini_rt *rt, int x, int y, t_vec color);
t_vec				ft_get_pixel_3(t_texture tex, float u, float v);
t_vec				ft_get_pixel_vec(char *addr, int line_lenght, int x, int y);

//-----render.c-----
int					ft_render(t_mini_rt *rt);
void				ft_draw_thread(t_mini_rt *rt, t_task task);
void				ft_inter_choice(t_calcul_color *info, t_vec2 inter);
t_vec				ft_calcul_color(t_mini_rt *rt, t_ray ray, int j,
						t_task task);
void				ft_calcul_viewport(t_mini_rt *rt);
float				ft_determine_eta(t_mini_rt *rt, t_vec point);

//-----ray.c-----
t_vec				ft_calcul_next_ray(t_mini_rt *rt, t_ray old_ray,
						t_calcul_color info, int j);
void				ft_calcul_reflected_ray(t_ray old_ray, t_ray *new_ray);
void				ft_calcul_refracted_ray(t_mini_rt *rt, t_ray old_ray,
						t_ray *new_ray, t_calcul_color info);

//-----color.c-----
t_vec				ft_final_color(t_mini_rt *rt, t_ray ray,
						t_calcul_color info);

//-----color_utils.c-----
t_vec				ft_gradient(t_vec color_a, t_vec color_b, float reflection);
t_vec				ft_ambient_color(t_mini_rt *rt, t_ray ray, t_task task);
t_vec				ft_tex_color(t_mini_rt *rt, float min, int i_min,
						t_ray ray);

//-----inter_point.c-----
float				ft_choose_point(t_object obj, t_vec point);
void				ft_inter_choice(t_calcul_color *info, t_vec2 inter);

//-----inter_point_2.c-----
float				ft_point_metric(t_vec point, t_vec ref);
float				ft_point_in_sphere(t_object obj, t_vec point);

//-----checkcorner.c-----
int					ft_check_corner_pix_sky(t_mini_rt *rt, t_task task);
int					ft_check_corner_pix_obj(t_mini_rt *rt, t_calcul_color info,
						t_task task);

//-----bump.c-----
t_vec				ft_bump_normal(t_mini_rt *rt, t_ray old_ray,
						t_calcul_color info);

//-----opti.c-----
void				ft_create_opti(t_mini_rt *rt, t_task task,
						t_calcul_color *info);
void				ft_do_opti(t_mini_rt *rt, t_task task, t_calcul_color *info,
						t_ray ray);
int					ft_did_i_do_the_opti(t_mini_rt *rt, int j, t_task task);

#endif