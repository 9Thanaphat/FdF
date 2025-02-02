#include "fdf.h"

int *ft_join_int_array(int *i1, int i2, int i1_size)
{
    int *join_int_array;
    int i;

    join_int_array = malloc((i1_size + 1) * sizeof(int));
    if (!join_int_array)
        return (NULL);

    i = 0;
    while (i < i1_size)
    {
        if (i1)  // ตรวจสอบว่า i1 ไม่เป็น NULL
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
	char	**ptr_to_split;
	char	**ptr_to_color;
	int		count_col;

	grid->col = 0;
	grid->row = 0;
	while ((read = get_next_line(fd)))
	{
    	read = ft_trim_newline(read);
		ptr_to_split = ft_split(read, ' ');
		count_col = 0;

		while (ptr_to_split[count_col] != NULL)
		{
			if (ft_strchr(ptr_to_split[count_col], ','))
			{
				ptr_to_color = ft_split(ptr_to_split[count_col], ',');
				if (!(grid->array = ft_join_int_array(grid->array, ft_atoi(ptr_to_color[0]), grid->array_size)))
					return (-1);
				get_min_max(grid, ft_atoi(ptr_to_color[0]));
				free_split(ptr_to_color);
			}
			else
			{
				if (!(grid->array = ft_join_int_array(grid->array, ft_atoi(ptr_to_split[count_col]), grid->array_size)))
					return (-1);
				get_min_max(grid, ft_atoi(ptr_to_split[count_col]));
			}
			grid->array_size++;
			count_col++;
		}
		// ตรวจสอบจำนวนคอลัมน์
		if (grid->row == 0)
			grid->col = count_col;  // บันทึกจำนวนคอลัมน์จากแถวแรก
		else if (count_col != grid->col)
		{
			ft_printf("Error: Column count mismatch at row %d (Expected %d columns, found %d columns)\n",
				grid->row + 1, grid->col, count_col);
			free_split(ptr_to_split);
			free(read);
			while ((read = get_next_line(fd)))
				free(read);
			close(fd);
			free(grid->array);
			return (-1);
		}
		free_split(ptr_to_split);
		free(read);
		grid->row++;
	}
	close(fd);
	return (0);
}

int	read_file(char *file_name, t_grid *grid)
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
		return (-1);
	}
	return(ft_put_to_array(fd, grid));
}
