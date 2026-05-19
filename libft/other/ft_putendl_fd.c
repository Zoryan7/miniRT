/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:14:55 by etessoer          #+#    #+#             */
/*   Updated: 2025/10/17 12:14:55 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
	if (write(fd, "\n", 1))
		return ;
}
