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

char	**ft_split(char const *s, char c);
void	draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win, int color);
float	toIso_x(t_cord* c);
float	toIso_y(t_cord* c);

#endif
