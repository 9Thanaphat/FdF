/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:09:00 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/25 22:12:14 by ttangcha         ###   ########.fr       */
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

int	get_color(t_list **node, t_env *env, char *split)
{
	char	**split_color;

	env->check = 0;
	if (ft_strchr(split, ','))
	{
		split_color = ft_split(split, ',');
		if (!split_color)
			return (-1);
		env->check = check_valid(split_color[0]);
		env->value = ft_atoi(split_color[0]);
		env->color = hex_to_int(split_color[1]);
		free_split(split_color);
	}
	else
	{
		env->check = check_valid(split);
		env->value = ft_atoi(split);
		env->color = -1;
	}
	if (*node == NULL)
		*node = create_node(env->value, env->color);
	else
		insert_node(*node, env->value, env->color);
	get_min_max(env, env->value);
	return (env->check);
}

int	is_directory(char *path)
{
	int	fd;

	fd = open(path, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (0);
	}
	return (-1);
}

int	read_to_array(t_env *env, t_list **node)
{
	char	*read;
	char	**split;

	read = get_next_line(env->fd);
	while (read)
	{
		read = ft_trim_newline(read);
		split = ft_split(read, ' ');
		env->count_col = 0;
		while (split[env->count_col] != NULL)
		{
			if ((get_color(node, env, split[env->count_col])) == -1)
				return (free_read(env, node, read, split));
			env->count_col++;
		}
		if (env->row == 0)
			env->col = env->count_col;
		else if (env->count_col != env->col)
			return (free_read(env, node, read, split));
		free_split(split);
		free(read);
		env->row++;
		read = get_next_line(env->fd);
	}
	return (read_to_array_extend(env, node));
}

int	read_file(char *file_name, t_env *env)
{
	t_list	*node;

	if (is_fdf(file_name) != 0)
		return (-1);
	node = NULL;
	set_env(env);
	if (is_directory(file_name) == 0)
		return (-1);
	env->fd = open(file_name, O_RDONLY);
	if (env->fd < 0)
		return (-1);
	return (read_to_array(env, &node));
}
