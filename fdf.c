#include "fdf.h"
#include "mlx.h"


void draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        mlx_pixel_put(mlx, win, x1, y1, 0xFFFFFF); 
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

struct cord {
    int x;
    int y;
    int z;
};

int main() {
    int size_x = 19;
    int size_y = 12;

    int *mlx_connection;
    int *mlx_window;

    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, 1920, 1080, "mywindow");
    

    int array[12][19] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // c = 18
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // c = 37
        {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0},
        {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
        {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
        {0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0},
        {0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    struct cord crd[size_x * size_y];

    int x = 0;
    int y = 0;
    int c = 0;
    int start_x = 100;
    int start_y = 100;
    int gap = 50;
    while (y < size_y) //fill in array
    {
        while (x < size_x)
        {
            crd[c].x = x * gap;
            crd[c].y = y * gap;
            crd[c].z = array[y][x];
            c++;
            x++;
        }
        x = 0;
        y++;
    }

    x = 0;
    y = 0;
    c = 0;
    int *array_sturct[12][19];
    while (y < size_y) //fill in array
    {
        while (x < size_x)
        {
            array_sturct[y][x] = &crd[c];
            c++;
            x++;
        }
        x = 0;
        y++;
    }

    x = 0;
    y = 0;
    c = 0;
    while (y < size_y)
    {
        while (x < size_x)
        {
            printf("cord[%d] = x:%d y:%d z:%d\n", c, crd[c].x, crd[c].y, crd[c].z);
            mlx_pixel_put(mlx_connection, mlx_window, crd[c].x + start_x, crd[c].y + start_y, 0xFFFFFF);
            c++;
            x++;
        }
        x = 0;
        y++;
    }
    x = 0;
    y = 0;
    c = 0;
    int count_x = 0;
    while (y < size_y)
    {
        while (x < size_x) // x < 19
        {
            if (count_x == size_x - 1)
                draw_line(crd[c].x + start_x, crd[c].y + start_y, crd[c].x + start_x, crd[c].y + start_y, mlx_connection, mlx_window);
            else 
                draw_line(crd[c].x + start_x, crd[c].y + start_y, crd[c + 1].x + start_x, crd[c + 1].y + start_y, mlx_connection, mlx_window);
            c++;
            x++;
            count_x++;
        }
        count_x = 0;
        x = 0;
        y++;
    }

    x = 0;
    y = 0;
    c = 0;
    while (y < size_y)
    {
        while (x < size_x) // x < 19
        {
            array_sturct[y][x];
            c++;
            x++;
        }
        x = 0;
        y++;
    }


    mlx_loop(mlx_connection);
    return 0;
}