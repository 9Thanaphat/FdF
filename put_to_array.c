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

void	test_print(char **ptr)
{
	int i = 0;
	while (ptr[i] != NULL)
	{
		printf("%s ", ptr[i]);
		i++;
	}
	printf("\n");
}

void ft_put_to_int_array(char *line, t_grid *grid)
{
	char	**ptr;
	int		i;
	int		j;

	ptr = ft_split(line, ' ');
	if (!ptr)
		return;
	test_print(ptr);

	i = 0;
	j = 0;
	grid->read_array = malloc(sizeof(int *) * grid->row);
	while (j < grid->row){
		grid->read_array[j] = malloc(sizeof(int) * grid->col);
		while (i < grid->col) {
			if (ptr[j * grid->col + i] != NULL)
				grid->read_array[j][i] = ft_atoi(ptr[j * grid->col + i]);
			else
				grid->read_array[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
	free(ptr);
	free(line);
}

void ft_put_to_array(int fd, t_grid *grid, char *line)
{
	char	*read;
	int		row;
	int		col;

	row = 0;
	col = 0;
	line = calloc(1, 1);
	while ((read = get_next_line(fd))) {
		read = ft_trim_newline(read);
		if (row == 0) {
			char **ptr = ft_split(read, ' ');
			while (ptr[col] != NULL) col++;
			free(ptr);
		}
		line = ft_strjoin(line, read);
		free(read);
		row++;
	}
	close(fd);
	printf("row: %d col: %d\n", row, col);
	grid->row = row;
	grid->col = col;
	ft_put_to_int_array(line, grid);
}

void read_file(char *file_name, t_grid *grid) {
	int fd;
	char	*line;
	char	*read;

	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0) {
		printf("Error opening file");
		return;
	}
	ft_put_to_array(fd, grid, line);
}
