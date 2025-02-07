#include "fdf.h"

void	get_min_max(t_grid *grid, int val)
{
	if (val < grid->min)
		grid->min = val;
	if (val > grid->max)
		grid->max = val;
}

int chartonum(char c)
{
    if (c >= 'a' && c <= 'f')
        return ((c - 'a') + 10);
	else if (c >= 'A' && c <= 'F')
        return ((c - 'A') + 10);
    else if (c >= '0' && c <= '9')
        return (c - '0');
    else
        return (0);
}

int    to_rgb(char *s)
{
    int i;
    int r;
    int g;
    int b;

    r = 0;
    g = 0;
    b = 0;
    i = 0;
    while (s[i])
    {
        if (i == 3)
            b = chartonum(s[2]) * 16 + chartonum(s[3]);
        if (i == 5)
            g = chartonum(s[4]) * 16 + chartonum(s[5]);
        if (i == 7)
            r = chartonum(s[6]) * 16 + chartonum(s[7]);
        i++;
    }
    return (r << 16 | g << 8 | b);
}

int	to_array(t_grid *grid, t_list *node)
{
	int	i;
	int	j;

	grid->array = malloc(sizeof(t_list*) * (grid->col * grid->row));
	if (!grid->array)
		return (-1);
	j = 0;
	while (j < grid->row)
	{
		i = 0;
		while (i < grid->col)
		{
			if(!node)
				return 0;
			grid->array[j * grid->col + i] = node;
			node->x = i;
			node->y = j;
			node->temp_x = i;
			node->temp_y = j;
			node->temp_z = node->z;
			node = node->next;
			i++;
		}
		j++;
	}
	return (0);
}


int	ft_put_to_array(int fd, t_grid *grid, t_list *node)
{
	char	*read;
	char	**ptr_to_split;
	char	**ptr_to_color;
	int		count_col;

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
				if (node == NULL)
					node = create_node(ft_atoi(ptr_to_color[0]), to_rgb(ptr_to_color[1]));
				else
					insert_node(node, ft_atoi(ptr_to_split[count_col]), to_rgb(ptr_to_color[1]));
				get_min_max(grid, ft_atoi(ptr_to_color[0]));
				free_split(ptr_to_color);
			}
			else
			{
				if (node == NULL)
					node = create_node(ft_atoi(ptr_to_split[count_col]), 0);
				else
					insert_node(node, ft_atoi(ptr_to_split[count_col]), 0);
				get_min_max(grid, ft_atoi(ptr_to_split[count_col]));
			}
			count_col++;
		}
		if (grid->row == 0)
			grid->col = count_col;
		else if (count_col != grid->col)
		{
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
	to_array(grid, node);
	return (0);
}

int	read_file(char *file_name, t_grid *grid)
{
	int		fd;
	char	*read;
	t_list 	*node;

	node = NULL;
	grid->angle_x = 0;
	grid->angle_y = 0;
	grid->angle_z = 0;
	grid->col = 0;
	grid->row = 0;
	grid->start_x = 0;
	grid->start_y = 0;
	grid->tile_size = 5;
	grid->height = 1;
	grid->min = 0;
	grid->max = 0;
	grid->array = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file");
		return (-1);
	}
	return(ft_put_to_array(fd, grid, node));
}
