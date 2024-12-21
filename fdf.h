#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "get_next_line.h"
# include <string.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct{
	float	x;
	float	y;
	float	z;
} t_cord;

typedef struct{
	int	*mlx_ptr;
	int	*mlx_window;
} t_vars;

typedef struct{
	int	row;
	int	col;
	int	**read_array;
} t_grid;

char	**ft_split(char const *s, char c);
void	draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win, int color);
float	toIso_x(t_cord* c);
float	toIso_y(t_cord* c);
void	read_file(char *file_name, t_grid *grid);
void	put_to_struct(t_cord **c, t_grid grid, int gap, int **array);
void	draw_line_horizontal(t_grid grid, t_cord **c, t_vars vars, int start_x, int start_y);
void	draw_line_vertical(t_grid grid, t_cord **c, t_vars vars, int start_x, int start_y);
#endif
