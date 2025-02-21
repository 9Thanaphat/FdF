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
# define KEY_MINUS 45
# define KEY_PLUS 61
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_Z 122
# define KEY_X 120
# define KEY_PAGE_UP 65365
# define KEY_PAGE_DOWN 65366
# define KEY_DEL 65535
# define KEY_R 114
# define KEY_CTRL 65307

typedef struct s_list
{
	double			x;
	double			y;
	double			z;
	double			temp_x;
	double			temp_y;
	double			temp_z;
	int				color;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*last;
}	t_list;

typedef struct s_points
{
	int		color1;
	int		color2;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	int		z1;
	int		z2;
	int	dx;
	int	dy;
	int	dz;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	int	total_steps;
}	t_points;

typedef struct s_env
{
	float	a_x;
	float	a_y;
	float	a_z;
	int		row;
	int		col;
	int		offset_x;
	int		offset_y;
	float	z_factor;
	int		z_factor_select;
	int		cell_size;
	int		color1;
	int		color2;
	t_list	**array;
	int	min;
	int	max;
	int	env_ui;
}	t_env;

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
	t_env	*env;
	t_data	*img_ptr;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_points *points, t_vars *vars);
void	my_clear_img(t_data *data);
int		read_file(char *file_name, t_env *env);
int		to_array(t_env *env, t_list *node);
void	draw_line_horizontal(t_env *env, t_vars *vars, t_data *img);
void	draw_line_vertical(t_env *env, t_vars *vars, t_data *img);
int		ft_gradient(int color1, int color2, int percent);
float	ft_map(float value, float in_min, float in_max);
char	*ft_trim_newline(char *str);
void	free_split(char **split);
int		free_read(t_env *env,t_list **node, int fd, char *read, char **split);
int		read_to_array_extend(int fd, t_env *env, t_list **node);
int		key_press(int keycode, t_vars *vars);
int		close_window(t_vars *vars);
t_list	*create_node(int height, int color);
void	insert_node(t_list *head_node, int height, int color);
void	array_to_node(t_env *env, t_list *node, int index);
void	rotate(t_list *node, t_env *env, float *sx, float *sy);
void	env_ui(t_vars *vars);
int		chartonum(char c);
int		to_rgb(char *s);
void	get_min_max(t_env *env, int val);
void	text_display(t_vars *vars);
void	set_env(t_env *env);

#endif
