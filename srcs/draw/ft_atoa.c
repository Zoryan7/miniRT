/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:20:21 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/27 14:22:16 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static char	*ft_other(int n, t_keycode_dict **dict)
{
	t_keycode_dict	*current;

	current = *dict;
	while (current)
	{
		if (current->keycode == n)
			return (current->name);
		current = current->next;
	}
	return ("Err");
}

char	*ft_atoa(int n, char *dst, t_keycode_dict **dict)
{
	if (n == 32)
		return ("Space");
	else if (ft_isprint(n))
	{
		dst[0] = n;
		return (dst);
	}
	else
		return (ft_other(n, dict));
	return ("Err");
}
