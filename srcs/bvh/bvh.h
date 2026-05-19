/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 13:38:56 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/15 05:05:20 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "../mini_rt.h"

typedef struct s_create_bvh
{
	int		stack[64];
	t_bvh	*parent;
	t_bvh	*left;
	t_bvh	*right;
	int		i;

}			t_create_bvh;

/* calcul_min */
t_vec		ft_calcul_min(t_object object);
/* calcul_max */
t_vec		ft_calcul_max(t_object object);

/* child_bvh */
float		ft_choose_center(t_object *object, char axis);
float		ft_choose_longest_axis(t_aabb dest, char *axis);
int			ft_which_side_bvh(int i, t_bvh *parent, t_mini_rt *rt);
t_aabb		ft_grow_bvh(t_bvh *dest, t_mini_rt *rt);

/* bvh_utils */
t_bvh_array	*ft_create_array_bvh(int nb);
t_bvh		*ft_new_bvh_node(int nb_object);
int			ft_count_object_without_plane(t_mini_rt *rt);
void		ft_compare_temp_with_global(t_aabb temp, t_aabb *global_box,
				t_vec origin);

/* bvh_utils_2 */
t_aabb		ft_recup_min_max(t_object object);
void		ft_split_bvh_2(t_bvh **left, t_bvh **right, t_mini_rt *rt, int lvl);
int			ft_affect_to_each_object(t_bvh *parent, t_bvh *left, t_bvh *right,
				t_mini_rt *rt);

/* bvh */
t_aabb		ft_recup_min_max(t_object object);
void		ft_compare_temp_with_global(t_aabb temp, t_aabb *global_box,
				t_vec origin);
t_bvh_array	*ft_bvh(t_mini_rt *rt);

/* global_node */
t_aabb		ft_initialize_global_box(void);
int			ft_calcul_nb_object_root(t_object *object, int size,
				int *index_object);
t_aabb		ft_first_bounding_box(t_mini_rt *rt);
t_bvh_array	*ft_global_node(t_mini_rt *rt);

#endif