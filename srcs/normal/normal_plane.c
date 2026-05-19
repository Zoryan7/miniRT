/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 03:53:44 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 03:54:37 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"

t_vec	ft_normal_plane(t_object object, t_ray ray)
{
	if (ft_vec_dot(object.vec, ray.direction) > 0)
		return (ft_vec_scale(object.vec, -1.0f));
	return (object.vec);
}
