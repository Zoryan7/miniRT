/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:00:41 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 04:36:45 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_has_to_moov(t_mini_rt *rt, t_vec *move)
{
	move->x = ((char)rt->input.right - (char)rt->input.left);
	move->y = ((char)rt->input.up - (char)rt->input.down);
	move->z = ((char)rt->input.forward - (char)rt->input.backward);
}

void	ft_moov(t_mini_rt *rt, unsigned long elapsed)
{
	float	speed;
	t_vec	move;

	speed = rt->info.speed * (float)elapsed / 1e6;
	ft_has_to_moov(rt, &move);
	if (!move.x && !move.y && !move.z && !rt->move_on)
		return ;
	rt->nb_img = 0;
	if (move.z)
		rt->camera.coord = ft_vec_add(rt->camera.coord,
				(ft_vec_scale(rt->camera.forward, move.z * speed)));
	if (move.x)
		rt->camera.coord = ft_vec_add(rt->camera.coord,
				(ft_vec_scale(rt->camera.right, move.x * speed)));
	if (move.y)
		rt->camera.coord = ft_vec_add(rt->camera.coord,
				(ft_vec_scale((t_vec){{0, 1, 0, 0}}, move.y * speed)));
	ft_rotate(rt, (t_vec){{(float)rt->camera.rot_x * M_PI / 180.0,
		(float)rt->camera.rot_y * M_PI / 180.0, 0}});
}

void	ft_rotate(t_mini_rt *rt, t_vec rot)
{
	t_vec	new;
	t_vec	tmp;
	float	s;

	float (c) = cosf(rot.x);
	s = sinf(rot.x);
	tmp.x = rt->camera.init_forward.x;
	tmp.y = (rt->camera.init_forward.y * c) - (rt->camera.init_forward.z * s);
	tmp.z = (rt->camera.init_forward.y * s) + (rt->camera.init_forward.z * c);
	c = cosf(rot.y);
	s = sinf(rot.y);
	new.x = (tmp.x * c) + (tmp.z * s);
	new.y = tmp.y;
	new.z = (-s * tmp.x) + (tmp.z * c);
	tmp.v = new.v;
	c = cosf(rot.z);
	s = sinf(rot.z);
	new.x = (tmp.x * c) - (tmp.y * s);
	new.y = (tmp.x * s) + (tmp.y * c);
	new.z = tmp.z;
	rt->camera.forward = ft_vec_normalize(new);
	rt->camera.right = ft_vec_normalize(ft_vec_cross((t_vec){{0, 1, 0, 0}},
				rt->camera.forward));
	rt->camera.up = ft_vec_normalize(ft_vec_cross(rt->camera.forward,
				rt->camera.right));
}

static void	ft_rot_obj_spec(t_mini_rt *rt)
{
	if (rt->object[rt->selec].type == cone)
		rt->object[rt->selec].specificites.cone.apex = \
		ft_vec_add(rt->object[rt->selec].coord,
				ft_vec_scale(rt->object[rt->selec].vec,
					rt->object[rt->selec].specificites.cone.height));
}

void	ft_rotate_obj(t_mini_rt *rt, t_vec rot)
{
	t_vec	new;
	t_vec	tmp;
	float	c;
	float	s;

	c = cosf(rot.x);
	s = sinf(rot.x);
	tmp.x = rt->object[rt->selec].init_vec.x;
	tmp.y = (rt->object[rt->selec].init_vec.y * c)
		- (rt->object[rt->selec].init_vec.z * s);
	tmp.z = (rt->object[rt->selec].init_vec.y * s)
		+ (rt->object[rt->selec].init_vec.z * c);
	c = cosf(rot.y);
	s = sinf(rot.y);
	new.x = (tmp.x * c) + (tmp.z * s);
	new.y = tmp.y;
	new.z = (-s * tmp.x) + (tmp.z * c);
	tmp.v = new.v;
	c = cosf(rot.z);
	s = sinf(rot.z);
	new.x = (tmp.x * c) - (tmp.y * s);
	new.y = (tmp.x * s) + (tmp.y * c);
	new.z = tmp.z;
	rt->object[rt->selec].vec = ft_vec_normalize(new);
	ft_rot_obj_spec(rt);
}
