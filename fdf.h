#ifndef FDF_H
# define FDF_H
# ifndef SCREEN_WIDTH 
#  define SCREEN_WIDTH 1920
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 1080
# endif
# include "mlx.h"
# include "get_next_line.h"
# include <string.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef struct{
	int	row;
	int	col;
	int	start_x;
	int	start_y;
	int	height;
	int	tile_size;
	int	**read_array;
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


char	**ft_split(char const *s, char c);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win, int color, t_data *img);
void	my_clear_img(t_data *data, int w, int h);
float	toIso_x(t_grid *grid, int x, int y);
float	toIso_y(t_grid *grid, int x, int y);
void	read_file(char *file_name, t_grid *grid);
void	draw_line_horizontal(t_grid *grid, t_vars *vars, t_data *img);
void	draw_line_vertical(t_grid *grid, t_vars *vars, t_data *img);

#endif
