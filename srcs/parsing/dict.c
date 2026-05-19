/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:26:52 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/08 17:32:59 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_keycode_dict	*ft_create_dict(void)
{
	t_keycode_dict	*dict;

	dict = NULL;
	ft_add_dict(&dict, ft_create_node_dict("F1", 65470));
	ft_add_dict(&dict, ft_create_node_dict("F2", 65471));
	ft_add_dict(&dict, ft_create_node_dict("F3", 65472));
	ft_add_dict(&dict, ft_create_node_dict("F4", 65473));
	ft_add_dict(&dict, ft_create_node_dict("F5", 65474));
	ft_add_dict(&dict, ft_create_node_dict("F6", 65475));
	ft_add_dict(&dict, ft_create_node_dict("F7", 65476));
	ft_add_dict(&dict, ft_create_node_dict("F8", 65477));
	ft_add_dict(&dict, ft_create_node_dict("F9", 65478));
	ft_add_dict(&dict, ft_create_node_dict("F10", 65479));
	ft_add_dict(&dict, ft_create_node_dict("F11", 65480));
	ft_add_dict(&dict, ft_create_node_dict("F12", 65481));
	ft_add_dict(&dict, ft_create_node_dict("del", 65535));
	ft_add_dict(&dict, ft_create_node_dict("home", 65360));
	ft_add_dict(&dict, ft_create_node_dict("end", 65367));
	ft_add_dict(&dict, ft_create_node_dict("ciel", 65365));
	ft_add_dict(&dict, ft_create_node_dict("pgdn", 65366));
	ft_add_dict(&dict, ft_create_node_dict("tab", 65289));
	ft_add_dict(&dict, ft_create_node_dict("caps", 65509));
	ft_add_dict(&dict, ft_create_node_dict("shftL", 65505));
	ft_add_dict(&dict, ft_create_node_dict("shftR", 65506));
	return (ft_create_dict_2(dict));
}

t_keycode_dict	*ft_create_dict_2(t_keycode_dict *dict)
{
	ft_add_dict(&dict, ft_create_node_dict("ctrlL", 65507));
	ft_add_dict(&dict, ft_create_node_dict("ctrlR", 65508));
	ft_add_dict(&dict, ft_create_node_dict("altL", 65513));
	ft_add_dict(&dict, ft_create_node_dict("altR", 65514));
	ft_add_dict(&dict, ft_create_node_dict("enter", 65293));
	ft_add_dict(&dict, ft_create_node_dict("supr", 65288));
	ft_add_dict(&dict, ft_create_node_dict("up", 65362));
	ft_add_dict(&dict, ft_create_node_dict("left", 65361));
	ft_add_dict(&dict, ft_create_node_dict("down", 65364));
	ft_add_dict(&dict, ft_create_node_dict("right", 65363));
	ft_add_dict(&dict, ft_create_node_dict("Scrol", 65300));
	ft_add_dict(&dict, ft_create_node_dict("Insrt", 65379));
	ft_add_dict(&dict, ft_create_node_dict("Pause", 65299));
	ft_add_dict(&dict, ft_create_node_dict("0", 65438));
	ft_add_dict(&dict, ft_create_node_dict("1", 65436));
	ft_add_dict(&dict, ft_create_node_dict("2", 65433));
	ft_add_dict(&dict, ft_create_node_dict("3", 65435));
	ft_add_dict(&dict, ft_create_node_dict("4", 65430));
	ft_add_dict(&dict, ft_create_node_dict("5", 65437));
	ft_add_dict(&dict, ft_create_node_dict("6", 65432));
	ft_add_dict(&dict, ft_create_node_dict("7", 65429));
	ft_add_dict(&dict, ft_create_node_dict("8", 65431));
	ft_add_dict(&dict, ft_create_node_dict("9", 65434));
	ft_add_dict(&dict, ft_create_node_dict(".", 65439));
	return (ft_create_dict_3(dict));
}

t_keycode_dict	*ft_create_dict_3(t_keycode_dict *dict)
{
	ft_add_dict(&dict, ft_create_node_dict("enter", 65439));
	ft_add_dict(&dict, ft_create_node_dict("+", 65451));
	ft_add_dict(&dict, ft_create_node_dict("-", 65453));
	ft_add_dict(&dict, ft_create_node_dict("*", 65450));
	ft_add_dict(&dict, ft_create_node_dict("/", 65455));
	ft_add_dict(&dict, ft_create_node_dict("vNum", 65407));
	return (dict);
}

t_keycode_dict	*ft_create_node_dict(char *name, int keycode)
{
	t_keycode_dict	*node;

	node = ft_gc_malloc(1, sizeof(t_keycode_dict), keycode_type);
	node->name = name;
	node->keycode = keycode;
	node->next = NULL;
	return (node);
}

void	ft_add_dict(t_keycode_dict **head, t_keycode_dict *node)
{
	t_keycode_dict	*current;

	if (!*head)
	{
		*head = node;
		return ;
	}
	current = *(head);
	while (current->next)
		current = current->next;
	current->next = node;
}
