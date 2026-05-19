/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_json_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:53:31 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/14 23:30:12 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_json.h"

int	ft_split_value_key(char *line, char **key, char **value)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ':');
	if (!split)
		return (1);
	while (split && split[i])
		i++;
	if (i != 2)
		return (1);
	*key = split[0];
	*value = split[1];
	free(split);
	return (0);
}

int	ft_cmp_key(char *key, char *cmp, int pos)
{
	int	i;
	int	len;

	i = 0;
	if (ft_skip_space(&i, key, 0))
		return (1);
	len = ft_strlen(cmp);
	if (ft_strncmp(key + i, cmp, len))
		return (1);
	i += len;
	if (pos == 0 && (ft_skip_space(&i, key, 0) || key[i] != ':'))
		return (1);
	else if (pos == 7)
	{
		if (ft_skip_space(&i, key, 0) || key[i] != ':')
			return (1);
		i++;
		if (ft_skip_space(&i, key, 1) || key[i] != 0)
			return (1);
	}
	else if (ft_skip_space(&i, key, 1) || key[i] != 0)
		return (1);
	return (0);
}

int	ft_ratio_positive(float *dest, char *name, char *value)
{
	if (ft_parse_ratio(value, dest, name))
		return (1);
	if (*dest < 0.0f)
		return (ft_putstr_fd("Error: ", 2), ft_putstr_fd(name, 2),
			ft_putstr_fd(" must be positive\n", 2), 1);
	return (0);
}

int	ft_add_value_to_key_object(t_texture_list *textures, t_object_info *dest,
		char *key, char *value)
{
	if (ft_cmp_key(key, "\"coordinates\"", 1) == 0)
		return (ft_parse_coordinates(value, &dest->object.coord));
	if (ft_cmp_key(key, "\"color\"", 1) == 0)
		return (ft_parse_color(value, &dest->object.color));
	if (ft_cmp_key(key, "\"reflection\"", 1) == 0)
		return (ft_ratio_positive(&dest->object.reflection, "reflection",
				value));
	if (ft_cmp_key(key, "\"transparency\"", 1) == 0)
		return (ft_ratio_positive(&dest->object.transparency, "transparency",
				value));
	if (ft_cmp_key(key, "\"refraction\"", 1) == 0)
		return (ft_ratio_positive(&dest->object.refraction_indice, "refraction",
				value));
	if (ft_cmp_key(key, "\"randomless\"", 1) == 0)
		return (ft_ratio_positive(&dest->object.randomless, "randomless",
				value));
	if (ft_cmp_key(key, "\"texture\"", 1) == 0)
		return (ft_parse_textures_json(textures, value,
				&dest->object.id_texture, "texture"));
	if (ft_cmp_key(key, "\"bump_map\"", 1) == 0)
		return (ft_parse_textures_json(textures, value, &dest->object.id_bump,
				"bump_map"));
	return (1);
}
