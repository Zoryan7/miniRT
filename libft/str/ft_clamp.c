/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:41:04 by etessoer          #+#    #+#             */
/*   Updated: 2026/03/25 11:41:17 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_clamp_name(char *str, size_t len)
{
	char	*new;
	int		i;

	if (ft_strlen(str) > len + 3)
	{
		new = ft_strndup(str, len);
		i = 0;
		while (i < 3)
		{
			new[len + i] = '.';
			i++;
		}
		return (new);
	}
	return (ft_strdup(str));
}
