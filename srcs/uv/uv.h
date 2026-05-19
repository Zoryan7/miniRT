/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:47:48 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:06:24 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UV_H
# define UV_H
# include "../mini_rt.h"

typedef struct s_all_axis	t_all_axis;

typedef struct s_triangle_info
{
	t_vec2	uv;
	t_vec	p;
	float	dot00;
	float	dot01;
	float	dot11;
	float	dot20;
	float	dot21;
	float	inv_denom;
}			t_triangle_info;

typedef struct s_rbox_info
{
	t_vec	axis_x;
	t_vec	axis_y;
	t_vec	axis_z;
	t_vec	local;
	t_vec2	uv;
	t_vec	half;
	t_vec	extent;
	float	axis_score_x;
	float	axis_score_y;
	float	axis_score_z;
}			t_rbox_info;

typedef struct s_plane_info
{
	t_vec	axis_x;
	t_vec	axis_y;
	t_vec	axis_z;
	t_vec2	uv;
	t_vec	local;
	float	scale;
}	t_plane_info;

typedef struct s_cylindre_info
{
	t_vec	axis_x;
	t_vec	axis_y;
	t_vec	axis_z;
	t_vec	local;
	t_vec2	uv;
	float	height;
}	t_cylindre_info;

//-----uv.c-----
t_vec2		ft_uv_object(t_object object, t_vec hit_point);

//-----uv_utils.c-----
void		ft_uv_basis(t_vec normal, t_vec up, t_all_axis axis);
t_vec		ft_uv_to_local(t_vec p, t_vec axis_x, t_vec axis_y, t_vec axis_z);
t_vec2		ft_uv_wrap(t_vec2 uv);
t_vec2		ft_uv_wrap_x(t_vec2 uv);
t_vec2		ft_uv_clamp(t_vec2 uv);

//-----uv_plane.c-----
t_vec2		ft_uv_plane(t_object object, t_vec hit_point);

//-----uv_triangle.c-----
t_vec2		ft_uv_triangle(t_object object, t_vec hit_point);

//-----uv_box.c-----
t_vec2		ft_uv_box(t_object object, t_vec hit_point);

//-----uv_rbox.c-----
t_vec2		ft_uv_rbox(t_object object, t_vec hit_point);

//-----uv_cylindre.c-----
t_vec2		ft_uv_cylinder(t_object object, t_vec hit_point);

//-----uv_cone.c-----
t_vec2		ft_uv_cone(t_object object, t_vec hit_point);

//-----uv_sphere.c
t_vec2		ft_uv_sphere(t_object object, t_vec hit_point);

#endif