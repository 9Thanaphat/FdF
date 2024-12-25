#include "fdf.h"

int ft_atoi(const char *nptr) {
    int i = 0, num = 0, neg = 1;
    while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)) i++;
    if (nptr[i] == '-' || nptr[i] == '+') {
        if (nptr[i] == '-') neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return num * neg;
}

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

void ft_put_to_array(int fd, t_grid *grid)
{
	char	*read;
	int		row;
	int		col;
	char	**ptr;

	row = 0;
	while (read = get_next_line(fd))
	{
		read = ft_trim_newline(read);
		ptr = ft_split(read, ' ');
		col = 0;
			while (ptr[col] != NULL)
			{
				grid->array = ft_join_int_array(grid->array, ft_atoi(ptr[col]), grid->array_size);
				grid->array_size++;
				col++;
			}
		free(ptr);
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

	grid->array = NULL;
	grid->array_size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0) {
		printf("Error opening file");
		return;
	}
	ft_put_to_array(fd, grid);
}
