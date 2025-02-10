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

int	free_read(t_env *env, int fd, char *read, char **split)
{
	printf("free read\n");
	free_split(split);
	free(read);
	while ((read = get_next_line(fd)))
	{
		free(read);
	}
	close(fd);
	free(env->array);
	return (-1);
}

int	read_to_array(int fd, t_env *env, t_list **node)
{
	char	*read;
	char	**split;
	int		count_col;

	while ((read = get_next_line(fd)))
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
			return (free_read(env, fd, read, split));
		free_split(split);
		free(read);
		env->row++;
	}
	close(fd);
	to_array(env, *node);
	return (0);
}

int	read_file(char *file_name, t_env *env)
{
	int		fd;
	char	*read;
	t_list	*node;

	node = NULL;
	set_env(env);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file\n");
		return (-1);
	}
	return (read_to_array(fd, env, &node));
}
