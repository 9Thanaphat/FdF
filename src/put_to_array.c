#include "fdf.h"

int	*ft_join_int_array(int *i1, int i2, int i1_size)
{
	int	*join_int_array;
	int	i;

	join_int_array = malloc((i1_size + 1) * sizeof(int));
	if (!join_int_array)
		return (NULL);
	i = 0;
	while (i < i1_size)
	{
		join_int_array[i] = i1[i];
		i++;
	}
	join_int_array[i] = i2;
	free(i1);
	return (join_int_array);
}

void	get_min_max(t_grid *grid, int val)
{
	if (val < grid->min)
		grid->min = val;
	if (val > grid->max)
		grid->max = val;
}

int	ft_put_to_array(int fd, t_grid *grid)
{
	char	*read;
	char	**ptr;
	char	**ptr_to;

	grid->row = 0;
	while (read = get_next_line(fd))
	{
		read = ft_trim_newline(read);
		ptr = ft_split(read, ' ');
		grid->col = 0;
		while (ptr[grid->col] != NULL)
			if (ft_strchr(ptr[grid->col], ','))
			{
				ptr_to = ft_split(ptr[grid->col], ',');
				grid->array = ft_join_int_array(grid->array, ft_atoi(ptr_to[0]), grid->array_size);
				get_min_max(grid, ft_atoi(ptr_to[0]));
				grid->array_size++;
				grid->col++;
				free_split(ptr_to);
			}
			else
			{
				grid->array = ft_join_int_array(grid->array, ft_atoi(ptr[grid->col]), grid->array_size);
				get_min_max(grid, ft_atoi(ptr[grid->col]));
				grid->array_size++;
				grid->col++;
			}
		free_split(ptr);
		free(read);
		grid->row++;
	}
	close(fd);
	grid->row = grid->row;
	grid->col = grid->col;
}

void	read_file(char *file_name, t_grid *grid)
{
	int		fd;
	char	*read;

	grid->start_x = 0;
	grid->start_y = 0;
	grid->tile_size = 20;
	grid->height = 8;
	grid->min = 0;
	grid->max = 0;
	grid->array = NULL;
	grid->array_size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file");
		return ;
	}
	ft_put_to_array(fd, grid);
}
