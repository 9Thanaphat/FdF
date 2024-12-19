#include "fdf.h"

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

int main(void)
{
	int fd;

	char *line;
	int count;
	count = 0;
	fd = open("pyra.fdf", O_RDONLY);

	if (fd < 0)
		return 1;
			while ((line = get_next_line(fd)) && count < 25) {
				printf("line %d : %s", count++, ft_trim_newline(line));
				free(line);
		}
		free(line);
		close(fd);

    int w = 20;
    int h = 20;
    int start_x = 900;
    int start_y = 100;

    int gap = 50;
    int *gap_ptr = &gap;

    int array[20][20] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, 0, 50, 50, 50, 0, 0, 0, 0, 0},
        {0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, 0, 50, 50, 50, 50, 0, 0, 0, 0},
        {0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, 50, 50, 0, 50, 50, 50, 0, 0, 0},
        {0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, 50, 50, 0, 0, 50, 50, 0, 0, 0},
        {0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, 50, 50, 0, 0, 50, 50, 0, 0, 0},
        {0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 50, 0, 0, 0},
        {0, 0, 0, 50, 50, 50, 50, 50, 0, 0, 0, 0, 0, 0, 50, 50, 50, 0, 0, 0},
        {0, 0, 0, 50, 50, 50, 50, 50, 0, 0, 0, 0, 0, 50, 50, 50, 0, 0, 0, 0},
        {0, 0, 0, 50, 50, 50, 50, 50, 0, 0, 0, 0, 50, 50, 50, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 50, 50, 0, 0, 0, 0, 50, 50, 50, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 50, 50, 0, 0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 50, 50, 0, 0, 0, 0, 50, 50, 50, 50, 50, 50, 0, 0, 0},
        {0, 0, 0, 0, 0, 50, 50, 0, 0, 0, 0, 50, 50, 50, 50, 50, 50, 0, 0, 0},
        {0, 0, 0, 0, 0, 50, 50, 0, 0, 0, 0, 50, 50, 50, 50, 50, 50, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    t_cord c[20][20];

    int i = 0;
    int j = 0;
    while (j < h)
    {
        while (i < w)
        {
            c[j][i].x = j * gap;
            c[j][i].y = i * gap;
            c[j][i].z = array[i][j];
            i++;
        }
        i = 0;
        j++;
    }

    int *mlx_ptr;
    int *mlx_window;

    mlx_ptr = mlx_init();
    mlx_window = mlx_new_window(mlx_ptr, 1920, 1080, "mywindow");

    //draw line left to right
    i = 0;
    j = 0;
    while (j < h)
    {
        while (i < w)
        {
            if (i < w - 1)
                draw_line(toIso_x(&c[j][i]) + start_x,
                toIso_y(&c[j][i]) + start_y,
                toIso_x(&c[j][i + 1]) + start_x,
                toIso_y(&c[j][i + 1]) + start_y,
                 mlx_ptr, mlx_window, 0xFFFFFF);
            i++;
        }
        i = 0;
        j++;
    }

    //draw line up to down
    i = 0;
    j = 0;
    while (i < w)
    {
        while (j < h)
        {
            if (j < h - 1)
                draw_line(toIso_x(&c[j][i]) + start_x,
                toIso_y(&c[j][i]) + start_y,
                toIso_x(&c[j + 1][i]) + start_x,
                toIso_y(&c[j + 1][i]) + start_y,
                mlx_ptr, mlx_window, 0xFFFFFF);
            j++;
        }
		j = 0;
		i++;
	}

	mlx_loop(mlx_ptr);
	return (0);
}
