/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:08:51 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 13:08:52 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*create_node(int z, int color)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node->z = z;
	new_node->color = color;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->last = new_node;
	return (new_node);
}

void	insert_node(t_list *head_node, int z, int color)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = create_node(z, color);
	last_node = head_node->last;
	last_node->next = new_node;
	new_node->next = NULL;
	head_node->last = new_node;
}

void	array_to_node(t_env *env, t_list *node, int i)
{
	if (!node)
		return ;
	env->array[i] = node;
	array_to_node(env, node->next, i + 1);
}
