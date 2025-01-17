#include "fdf.h"

char *ft_trim_newline(char *str) {
	int i = 0;
	while (str[i] != '\n' && str[i] != '\0') i++;
	if (str[i] == '\n') str[i] = ' ';
	return str;
}

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
		join_int_array[i] = i1[i];
		i++;
	}
	join_int_array[i] = i2;
	free(i1);
	return (join_int_array);
}

void get_min_max(t_grid *grid, int val)
{
	if (val < grid->min)
		grid->min = val;
	if (val > grid->max)
		grid->max = val;
}

void free_split(char **split) {
    int i = 0;
    if (!split)
        return;
    while (split[i]) {
        free(split[i]);
        i++;
    }
    free(split);
}

void ft_put_to_array(int fd, t_grid *grid)
{
	char	*read;
	int		row;
	int		col;
	char	**ptr;
	char	**ptr_to;

	row = 0;
	while (read = get_next_line(fd))
	{
		read = ft_trim_newline(read);
		ptr = ft_split(read, ' ');
		col = 0;
			while (ptr[col] != NULL)
				if (ft_strchr(ptr[col], ','))
				{
					ptr_to = ft_split(ptr[col], ',');
					grid->array = ft_join_int_array(grid->array, atoi(ptr_to[0]), grid->array_size);
					get_min_max(grid, atoi(ptr_to[0]));
					grid->array_size++;
					col++;
					free_split(ptr_to);
				}
				else
				{
					grid->array = ft_join_int_array(grid->array, atoi(ptr[col]), grid->array_size);
					get_min_max(grid, atoi(ptr[col]));
					grid->array_size++;
					col++;
				}
		free_split(ptr);
		free(read);
		row++;
	}
	close(fd);
	printf("row: %d col: %d\n", row, col);
	grid->row = row;
	grid->col = col;
}

void read_file(char *file_name, t_grid *grid) {
	int		fd;
	char	*read;

	grid->min = 0;
	grid->max = 0;
	grid->array = NULL;
	grid->array_size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0) {
		printf("Error opening file");
		return;
	}
	ft_put_to_array(fd, grid);
}
