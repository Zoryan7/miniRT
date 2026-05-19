/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:59:50 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 06:23:56 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# include "../mini_rt.h"

typedef struct s_intersect_bvh
{
	int					stack[64];
	t_bvh				*bvh_node;
	int					i;
	t_bvh				*child[2];
	t_vec2				inter[4];
}						t_intersect_bvh;

typedef struct s_rbox_basis
{
	t_vec				axis_x;
	t_vec				axis_y;
	t_vec				axis_z;
}						t_rbox_basis;

typedef struct s_rbox_trace
{
	t_vec				r_origin;
	t_vec				r_dir;
	t_vec				size;
	float				radius;
	float				bound_r;
	float				a;
	float				b;
	float				c;
	float				h;
	float				t0;
	float				t1;
	float				t;
	float				t_prev;
	float				d;
	float				d_prev;
	float				d_mid;
	float				lo;
	float				hi;
	float				mid;
	float				step;
	int					i;
}						t_rbox_trace;

typedef struct s_rbox_hit
{
	t_rbox_basis		basis;
	t_vec				ro_local;
	t_vec				rd_local;
	t_vec				half_size;
	t_vec2				inter;
	float				radius;
	float				sdf;
	float				hit;
}						t_rbox_hit;

/* intersection */
t_vec2					ft_choose_intersect(t_object object, t_ray ray);

t_vec2					ft_intersect_plane(const t_vec r_origin,
							const t_vec r_dir, const t_vec p, const float p_y);

/* intersection_bvh */
t_vec2					ft_intersect_bvh(t_ray ray, t_bvh_array *bvh,
							t_mini_rt *rt, t_calcul_color *info);

int						ft_intersect_bvh_light(t_ray ray, t_bvh_array *bvh,
							t_mini_rt *rt, t_calcul_color *info);

/* intersection_bvh_2 */
t_vec2					ft_leaf_bvh(t_ray ray, t_bvh *bvh_node, t_mini_rt *rt,
							t_calcul_color *info);
int						ft_leaf_bvh_light(t_ray ray, t_bvh *bvh_node,
							t_mini_rt *rt, t_calcul_color *info);
void					ft_initialize_intersect_bvh(t_bvh_array *bvh,
							t_intersect_bvh *data);
void					ft_check_child_box(t_ray ray, t_intersect_bvh *data,
							t_bvh_array *bvh);
void					ft_swap_bvh_2(t_intersect_bvh *data);
int						ft_next_bvh_node(t_intersect_bvh *data,
							t_bvh_array *bvh, t_calcul_color *info);

/* intersection_box */
void					ft_rbox_prepare(t_rbox_hit *box, t_ray ray,
							t_object obj);
int						ft_rbox_trace_start(t_rbox_trace *trace);
int						ft_rbox_trace_step(t_rbox_trace *trace);
float					ft_rbox_refine(t_rbox_trace *trace);

/* intersection_r_box_2*/
t_vec					ft_rbox_fallback_up(t_vec axis_z, t_vec up);
void					ft_rbox_basis_i(t_rbox_basis *basis, t_vec forward,
							t_vec up);
t_vec					ft_to_rbox_local_i(t_vec p, t_rbox_basis basis);
t_vec					ft_rbox_point(t_vec origin, t_vec dir, float t);
float					ft_rbox_sdf(t_vec p, t_vec half_size, float radius);

/* intersection_r_box*/
t_vec2					ft_intersect_r_box(t_ray ray, t_object obj);
float					ft_inter_button(t_vec r_origin, t_vec r_dir, t_vec size,
							float radius);

/* intersection_box */
static inline t_vec2	ft_intersect_box(t_ray ray, t_aabb box)
{
	t_vec	hit1;
	t_vec	hit2;
	float	t1;
	float	t2;
	t_vec	t_min_max[2];

	hit1.v = (box.min.v - ray.origin.v) * ray.r_direction.v;
	hit2.v = (box.max.v - ray.origin.v) * ray.r_direction.v;
	t_min_max[0] = ft_min_vec(hit1, hit2);
	t_min_max[1] = ft_max_vec(hit1, hit2);
	t1 = ft_maxf(t_min_max[0].x, ft_maxf(t_min_max[0].y, t_min_max[0].z));
	t2 = ft_minf(t_min_max[1].x, ft_minf(t_min_max[1].y, t_min_max[1].z));
	if (t2 < 0 || t1 > t2)
		return ((t_vec2){{-1, -1}});
	return ((t_vec2){{t1, t2}});
}

/* intersection_cone */
t_vec2					ft_intersect_cone(t_ray ray, t_object object);
void					ft_swap_t(float *a, float *b);

/* intersection_cylinder */
t_vec2					ft_chose_closest(t_vec2 t, t_vec2 t_bouchon);
t_vec2					ft_intersect_cylinder(t_ray ray, t_object object);

/* init_cylinder */
void					ft_init_all_t(t_vec2 t, t_vec2 t_bouchon, t_vec *all_t);
void					ft_init_min2_i(float *min1, float *min2, int *i);

#endif