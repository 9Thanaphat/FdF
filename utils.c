#include "fdf.h"

int ft_gradient(int start_color, int end_color, int steps, int i)
{
	int	r;
	int	g;
	int	b;

	r = ((start_color >> 16) & 0xFF) + ((((end_color >> 16) & 0xFF) - ((start_color >> 16) & 0xFF)) * (i / (float)(steps - 1)));
	g = ((start_color >> 8) & 0xFF) + ((((end_color >> 8) & 0xFF) - ((start_color >> 8) & 0xFF)) * (i / (float)(steps - 1)));
	b = ((start_color & 0xFF) + (((end_color & 0xFF) - (start_color & 0xFF)) * (i / (float)(steps - 1))));
	return (r << 16 | g << 8 | b);
}

float ft_map(float value, float in_min, float in_max, float out_min, float out_max)
{
	return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
