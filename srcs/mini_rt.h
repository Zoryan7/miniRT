/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:34:05 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 11:04:47 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H
# include "../libft/libft.h"
# include "mini_rt_struct.h"
# include "intersection/intersection.h"
# include "event/event.h"
# include "garbage_collector/garbage_collector.h"
# include "draw/draw.h"
# include "utils/utils.h"
# include "render/render.h"
# include "uv/uv.h"
# include "normal/normal.h"
# include "bvh/bvh.h"
# include "parsing/parsing.h"
# include "parsing/parsing_rt/parsing_rt.h"
# include "threading/threading.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <float.h>
# include <dirent.h>
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define GAUSS_RADIUS 40

#endif