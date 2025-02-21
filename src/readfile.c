/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:09:00 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 14:43:44 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	to_array(t_env *env, t_list *node)
{
	int	i;
	int	j;

	env->array = malloc(sizeof(t_list *) * (env->col * env->row));
	if (!env->array)
		return (-1);
	j = 0;
	while (j < env->row)
	{
		i = 0;
		while (i < env->col)
		{
			if (!node)
				return (0);
			env->array[j * env->col + i] = node;
			node->x = i;
			node->y = j;
			node = node->next;
			i++;
		}
		j++;
	}
	return (0);
}

void	get_color(t_list **node, t_env *env, char *split)
{
	char	**split_color;
	int		value;
	int		color;

	if (ft_strchr(split, ','))
	{
		split_color = ft_split(split, ',');
		if (!split_color)
			return ;
		value = ft_atoi(split_color[0]);
		color = to_rgb(split_color[1]);
		free_split(split_color);
	}
	else
	{
		value = ft_atoi(split);
		color = 0;
	}
	if (*node == NULL)
		*node = create_node(value, color);
	else
		insert_node(*node, value, color);
	get_min_max(env, value);
}

int	read_to_array(t_env *env, t_list **node)
{
	char	*read;
	char	**split;
	int		count_col;

	read = get_next_line(env->fd);
	while (read)
	{
		read = ft_trim_newline(read);
		split = ft_split(read, ' ');
		count_col = 0;
		while (split[count_col] != NULL)
		{
			get_color(node, env, split[count_col]);
			count_col++;
		}
		if (env->row == 0)
			env->col = count_col;
		else if (count_col != env->col)
			return (free_read(env, node, env->fd, read, split));
		free_split(split);
		free(read);
		env->row++;
		read = get_next_line(env->fd);
	}
	return (read_to_array_extend(env, node));
}

int	read_file(char *file_name, t_env *env)
{
	char	*read;
	t_list	*node;

	node = NULL;
	set_env(env);
	env->fd = open(file_name, O_RDONLY);
	if (env->fd < 0)
		return (-1);
	return (read_to_array(env, &node));
}
