/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:13:51 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 14:22:10 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_read(t_env *env, t_list **node, int fd, char *read, char **split)
{
	t_list *tmp;

	free_split(split);
	free(read);
	read = get_next_line(fd);
	while (read)
	{
		free(read);
		read = get_next_line(fd);
	}
	close(fd);
	while ((*node)->next != NULL)
	{
		tmp = *node;
		*node = (*node)->next;
		free(tmp);
	}
	free(*(node));
	return (-1);
}

int	close_window(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->env->col * vars->env->row)
	{
		free(vars->env->array[i]);
		i++;
	}
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr->img);
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_window);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->env->array);
	free(vars->mlx_ptr);
	exit(0);
	return (0);
}
