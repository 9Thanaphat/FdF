#include "fdf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			num = (num * 10) + (nptr[i] - 48);
		else
			break ;
		i++;
	}
	return (num * neg);
}
char *ft_trim_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		str[i] = ' ';
	return (str);
}

void	test_print(int *array, int col)
{
	int	i = 0;
	while (i < col)
	{
		printf("%d, ", array[i]);
		i++;
	}
	printf("\n");
}

void	ft_put_to_int_array(char *line, int row, int col, t_grid *grid)
{
	char	**ptr;
	int		i;
	int		j;

	j = 0;
	grid->read_array = malloc(sizeof(int*) * row);
	while (j < row)
		grid->read_array[j++] = malloc(sizeof(int) * col);
	ptr = ft_split(line, 32);
	i = 0;
	j = 0;
	while (j < row)
	{
		while (i < col)
			grid->read_array[j][i++] = ft_atoi(ptr[(j * col) + i]);
		test_print(grid->read_array[j], col);
		i = 0;
		j++;
	}
	free(ptr);
	free(line);
}

void	ft_put_to_array(int fd, char *line, t_grid *grid){
	int		row;
	int		col;
	char	*read;
	char	**ptr;

	row = 0;
	col = 0;
	while ((read = get_next_line(fd))) {
		read = ft_trim_newline(read);
		ptr = ft_split(read, 32);
		while (ptr[col] != NULL)
			col++;
		if (!line)
			line = calloc(1, 1);
		line = ft_strjoin(line, read);
		free(read);
		free(ptr);
		row++;
	}
	close(fd);
	printf("row: %d col: %d \n", row, col);
	grid->row = row;
	grid->col = col;
	
	ft_put_to_int_array(line, row, col, grid);
}

void read_file(char *file_name, t_grid *grid)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	ft_put_to_array(fd, line, grid);
}
