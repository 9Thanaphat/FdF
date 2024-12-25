#include "fdf.h"

static size_t	ft_getdigits(long int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			di;
	char		*strnum;
	long int	num;

	num = n;
	di = ft_getdigits(n);
	if (num < 0)
		num *= -1;
	strnum = (char *)malloc(sizeof(char) * (di + 1));
	if (!strnum)
		return (NULL);
	*(strnum + di) = '\0';
	while (di--)
	{
		*(strnum + di) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		strnum[0] = '-';
	return (strnum);
}

void text_display(t_vars *vars)
{
	mlx_string_put(vars->mlx_ptr, vars->mlx_window, 25, 25, 0xFFFFFF, "Tile Size :");
	mlx_string_put(vars->mlx_ptr, vars->mlx_window, 125, 25, 0xFFFFFF, ft_itoa(vars->grid_ptr->tile_size));
	mlx_string_put(vars->mlx_ptr, vars->mlx_window, 25, 50, 0xFFFFFF, "Tile Height :");
	mlx_string_put(vars->mlx_ptr, vars->mlx_window, 125, 50, 0xFFFFFF, ft_itoa(vars->grid_ptr->height));
}

int key_press(int keycode, t_vars *vars)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65362)
	{
		vars->grid_ptr->start_x -= 5;
		vars->grid_ptr->start_y -= 5;
	}
	else if (keycode == 65364)
	{
		vars->grid_ptr->start_x += 5;
		vars->grid_ptr->start_y += 5;
	}
	else if (keycode == 65361)
	{
		vars->grid_ptr->start_x -= 5;
		vars->grid_ptr->start_y += 5;
	}
	else if (keycode == 65363)
	{
		vars->grid_ptr->start_x += 5;
		vars->grid_ptr->start_y -= 5;
	}
	else if (keycode == 65365)
		vars->grid_ptr->height += 1;
	else if (keycode == 65366)
		vars->grid_ptr->height -= 1;
	else if (keycode == 61)
		vars->grid_ptr->tile_size += 0.1;
	else if (keycode == 45)
		vars->grid_ptr->tile_size -= 0.1;
	my_clear_img(vars->img_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	draw_line_horizontal(vars->grid_ptr, vars, vars->img_ptr);
	draw_line_vertical(vars->grid_ptr, vars, vars->img_ptr);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_window, vars->img_ptr->img, 0, 0);
	text_display(vars);
	return (0);
}

int main(int argc, char *argv)
{
	t_grid	grid;
	t_vars	vars;
	t_data	img;

	read_file("MGDS_WHOLE_WORLD_OCEAN1_M.fdf", &grid);
	printf ("in main | row :%d col:%d\n", grid.row, grid.col);

	int	x = 0;
	int	count = 1;
	while (grid.array[x] >= 0)
	{
		x++;
		count++;
	}
	printf("count : %d\n", count);

	grid.start_x = 0;
	grid.start_y = 0;
	grid.tile_size = 10;
	grid.height = 5;

	vars.mlx_ptr = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "mywindow");
	vars.grid_ptr = &grid;

	img.img = mlx_new_image(vars.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img_ptr = &img;
	draw_line_horizontal(&grid, &vars, &img);
	draw_line_vertical(&grid, &vars, &img);

	mlx_hook(vars.mlx_window, 2, 1L<<0, key_press, &vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_window, img.img, 0, 0);
	mlx_loop(vars.mlx_ptr);
	
	return (0);
}
