/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:23:14 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/10 10:28:51 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int	ft_intersect_bvh_point(float x, float y, float z, t_aabb box)
{
	if (x >= box.min.x && x < box.max.x && y >= box.min.y && y < box.max.y
		&& z >= box.min.z && z < box.max.z)
		return (1);
	return (0);
}
