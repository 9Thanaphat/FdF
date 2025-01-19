#include "fdf.h"

int main(int argc, char **argv)
{
	t_grid	grid;
	t_vars	vars;
	t_data	img;

	if (argc == 2)
		read_file(argv[1], &grid);
	else
	{
		ft_printf("use ./fdf [file]\n");
		return (0);
	}
	vars.mlx_ptr = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, argv[1]);
	vars.grid_ptr = &grid;
	img.img = mlx_new_image(vars.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	vars.img_ptr = &img;
	draw_line_horizontal(&grid, &vars, &img);
	draw_line_vertical(&grid, &vars, &img);
	mlx_hook(vars.mlx_window, 2, 1L<<0, key_press, &vars);
	mlx_hook(vars.mlx_window, 17, 0, close_window, &vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_window, img.img, 0, 0);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
