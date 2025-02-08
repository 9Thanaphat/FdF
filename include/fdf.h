#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <string.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define PI 3.141592653589793
# define WIDTH 1920
# define HEIGHT 1080
# define ESC 65307
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_Z 122
# define KEY_X 120

typedef struct s_list
{
	double				x;
	double				y;
	double				z;
	double				temp_x;
	double				temp_y;
	double				temp_z;
	int				color;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*last;
}	t_list;

typedef struct s_points
{
	int	index_1;
	int	index_2;

	float	iso_x1;
	float	iso_y1;
	float	iso_x2;
	float	iso_y2;
	int	z1;
	int	z2;

	int dx;
	int dy;
	int dz;
	int sx;
	int	sy;
	int err;
	int z;
}	t_points;

typedef struct s_grid
{
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int	row;
	int	col;
	int	start_x;
	int	start_y;
	int	height;
	int	tile_size;
	t_list	**array;
	int	min;
	int	max;
}	t_grid;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_grid	*grid_ptr;
	t_data	*img_ptr;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_points *points, t_vars *vars);
void	my_clear_img(t_data *data, int w, int h);
int		toIso_x(t_grid *grid, int x, int y);
int		toIso_y(t_grid *grid, int x, int y);
int		read_file(char *file_name, t_grid *grid);
void	draw_grid_lines(t_grid *grid, t_vars *vars, t_data *img);
void	draw_line_horizontal(t_grid *grid, t_vars *vars, t_data *img);
void	draw_line_vertical(t_grid *grid, t_vars *vars, t_data *img);

int 	ft_gradient(int color1, int color2, int percent);
float	ft_map(float value, float in_min, float in_max, float out_min, float out_max);
char	*ft_trim_newline(char *str);
void	free_split(char **split);

int key_press(int keycode, t_vars *vars);
int close_window(t_vars *vars);

t_list	*create_node(int height, int color);
void	insert_node(t_list *head_node, int height, int color);
void	array_to_node(t_grid *grid, t_list *node, int index);

void 	draw_edge(t_vars *vars);

#endif
