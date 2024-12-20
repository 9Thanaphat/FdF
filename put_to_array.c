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
		str[i] = 0;
	return (str);
}

int	**ft_put_to_array(int row, int col, int *array)
{
	char *line;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((line = get_next_line(fd))) {
		line = ft_trim_newline(line);
		char **ptr;
		ptr = ft_split(line, ' ');
		while (ptr[col] != NULL)
			col++;
		row++;
		free(line);
		close(fd);
	}

}

int	**ft_allocate_array(int row, int col){
	int	**array;
	int	i;

	i = 0;
	array = malloc(row * sizeof(int*));
	while (i < col)
	{
		array = malloc(col * sizeof(int));
		i++;
	}
	return (array);
}

int	**ft_get_map_size(){
	int fd;
	char *line;
	char **ptr_to_splited_lines;
	int	col;
	int row;

	col = 0;
	row = 0;
	fd = open("pyra.fdf", O_RDONLY);
	while ((line = get_next_line(fd))) {
		line = ft_trim_newline(line);
		ptr_to_splited_lines = ft_split(line, ' ');
		while (ptr_to_splited_lines[col] != NULL)
			col++;
		row++;
		free(line);
	}
	printf("counted : row : %d col : %d\n",row , col);
	ft_allocate_array(row, col);
	free(line);
	return (NULL);
}	