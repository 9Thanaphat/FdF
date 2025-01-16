#ifndef FDF_H
# define FDF_H
# ifndef SCREEN_WIDTH 
#  define SCREEN_WIDTH 1920
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 1080
# endif
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <string.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef struct s_points{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	z1;
	float	z2;
} t_points;

typedef struct s_grid{
	int	row;
	int	col;
	int	start_x;
	int	start_y;
	int	height;
	int	tile_size;
	int	*array;
	int	array_size;
	int *color;
	int	min;
	int	max;
} t_grid;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct{
	int		*mlx_ptr;
	int		*mlx_window;
	t_grid	*grid_ptr;
	t_data	*img_ptr;
} t_vars;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_points *points, t_vars *vars);
void	my_clear_img(t_data *data, int w, int h);
float	toIso_x(t_grid *grid, int x, int y);
float	toIso_y(t_grid *grid, int x, int y);
void	read_file(char *file_name, t_grid *grid);
void	draw_line_horizontal(t_grid *grid, t_vars *vars, t_data *img);
void	draw_line_vertical(t_grid *grid, t_vars *vars, t_data *img);

int		ft_abs(int num);
float	ft_map(float value, float in_min, float in_max, float out_min, float out_max);

#endif
