#include "fdf.h"

void	put_to_struct(t_cord **c, t_grid grid, int gap, int **array){
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < grid.row)
	{
		while (i < grid.col)
		{
			c[j][i].x = j * gap;
			c[j][i].y = i * gap;
			c[j][i].z = array[i][j] * 3;
			i++;
		}
		i = 0;
		j++;
	}
}
