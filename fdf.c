#include "fdf.h"
#include "mlx.h"



typedef struct{
    float   x;
    float   y;
    float   z;
} Cord; 

//iso_x = x - y หรือ iso_y = (x + y) / 2 - z
float toIso_x(Cord* c)
{
    return (c->x - c->y);
}

float toIso_y(Cord* c)
{
    return ((c->x + c->y) / 2 - c->z);
}

void draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        mlx_pixel_put(mlx, win, x1, y1, color); 
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}


int main(void)
{
    int w = 20;
    int h = 20;
    int start_x = 900;
    int start_y = 100;
    
    int gap = 50;

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

    Cord c[20][20];

    int i = 0;
    int j = 0;
    while (j < h)
    {
        while (i < w)
        {
            // printf("i:%d j:%d val:%d \n", i, j, array[j][i]);
            c[j][i].x = i * gap;
            c[j][i].y = j * gap;
            c[j][i].z = array[i][j];
            i++;
        }
        i = 0;
        j++;
    }

    //fill data to struct array
    printf("fill data to struct array\n");
    i = 0;
    j = 0;
    while (j < h)
    {
        while (i < w)
        {
            printf("(x:%.1f y:%.1f z:%.1f)", c[j][i].x, c[j][i].y ,c[j][i].z);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }

    //print convert to iso value
    printf("print convert to iso value\n");
    i = 0;
    j = 0;
    while (j < h)
    {
        while (i < w)
        {
            printf("(x:%.1f y:%.1f )", toIso_x(&c[j][i]), toIso_y(&c[j][i]));
            i++;
        }
        printf("\n");
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
                draw_line(toIso_x(&c[j][i]) + start_x, toIso_y(&c[j][i]) + start_y, toIso_x(&c[j][i + 1]) + start_x, toIso_y(&c[j][i + 1]) + start_y, mlx_ptr, mlx_window, 0xFC3D03);
            mlx_pixel_put(mlx_ptr, mlx_window, toIso_x(&c[j][i]) + start_x, toIso_y(&c[j][i]) + start_y, 0xFFFFFF);
            i++;
        }
        printf("\n");
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
                draw_line(toIso_x(&c[j][i]) + start_x, toIso_y(&c[j][i]) + start_y, toIso_x(&c[j + 1][i]) + start_x, toIso_y(&c[j + 1][i]) + start_y, mlx_ptr, mlx_window, 0x00C8FF);
            j++;
        }
        j = 0;
        i++;
    }

    //put cord point
    i = 0;
    j = 0;
    while (j < h)
    {
        while (i < w)
        {
            mlx_pixel_put(mlx_ptr, mlx_window, toIso_x(&c[j][i]) + start_x, toIso_y(&c[j][i]) + start_y, 0xFFFFFF);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }

    mlx_loop(mlx_ptr);
    return (0);
}
