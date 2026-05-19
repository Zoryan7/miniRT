/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:50:39 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 08:39:35 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H
# include "../mini_rt.h"

typedef struct s_all_axis	t_all_axis;

typedef struct s_info_rbox
{
	t_vec	normal;
	t_vec	hit_local;
	t_vec	ro_local;
	t_vec	rd_local;
	t_vec	axis_x;
	t_vec	axis_y;
	t_vec	axis_z;
}	t_info_rbox;

//-----normal.c-----
t_vec	ft_choose_normal(t_object object, float t, t_ray ray);

//-----normal_box.c-----
t_vec	ft_normal_box(t_aabb box, float t, t_ray ray);

//-----normal_cone.c-----
t_vec	ft_normal_cone(t_object object, float t, t_ray ray);

//-----normal_cylinder.c-----
t_vec	ft_normal_cylinder(t_object object, float t, t_ray ray);

//-----normal_plane.c-----
t_vec	ft_normal_plane(t_object object, t_ray ray);

//-----normal_r_box.c-----
t_vec	ft_normal_r_box(t_object object, float t, t_ray ray);

//-----normal_triangle.c-----
t_vec	ft_normal_triangle(t_object object, float t, t_ray ray);

//-----normal_sphere.c-----
t_vec	ft_normal_sphere(t_object object, float t, t_ray ray);

#endif