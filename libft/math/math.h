/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:39:10 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/01 13:46:36 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# include "../libft.h"
# include <math.h>

typedef float	t_v4sf __attribute__((vector_size(16)));
typedef float	t_v2sf __attribute__((vector_size(8)));

typedef union u_vec {
	t_v4sf	v;
	struct {
		float	x;
		float	y;
		float	z;
		float	w;
	};
	struct {
		float	width;
		float	height;
		float	depth;
		float	ww;
	};
	struct {
		float	r;
		float	g;
		float	b;
		float	t;
	};
	struct {
		float	a;
		float	bb;
		float	c;
		float	delta;
	};
} __attribute__((aligned(16)))	t_vec;

typedef union u_vec2 {
	t_v2sf	v;
	struct {
		float	x;
		float	y;
	};
} __attribute__((aligned(8)))	t_vec2;

int		ft_max(int a, int b);
float	ft_maxf(float a, float b);
int		ft_min(int a, int b);
float	ft_minf(float a, float b);
int		ft_abs(int a);
float	ft_absf(float a);
t_vec	ft_vec_normalize(t_vec v);
float	ft_vec_length(t_vec v);
t_vec	ft_vec_add(t_vec a, t_vec b);
t_vec	ft_vec_cross(t_vec a, t_vec b);
float	ft_vec_dot(t_vec a, t_vec b);
t_vec	ft_vec_scale(t_vec vec, float mult);
t_vec	ft_vec_divide(t_vec a, float mult);
t_vec	ft_vec_divide_vec(t_vec a, t_vec b);
t_vec	ft_vec_sub(t_vec a, t_vec b);
t_vec	ft_vec_mult(t_vec a, t_vec b);
t_vec	ft_vec_abs(t_vec vec);
t_vec	ft_vec_sqrt(t_vec vec);
float	ft_vec_length(t_vec v);
int		ft_signf(float a);
int		ft_sign(int a);
t_vec	ft_vec_sign(t_vec vec);
t_vec	ft_vec_max(t_vec a, t_vec b);
t_vec	ft_vec_min(t_vec a, t_vec b);
t_vec	ft_vec_sub_1(t_vec a, float mult);

t_vec	ft_min_vec(t_vec a, t_vec b);

t_vec	ft_max_vec(t_vec a, t_vec b);
#endif