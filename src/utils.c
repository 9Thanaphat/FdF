#include "fdf.h"

char	*ft_trim_newline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		str[i] = ' ';
	return (str);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int ft_gradient(int color1, int color2, int steps, int i)
{
	int	r;
	int	g;
	int	b;

	r = ((color1 >> 16) & 0xFF) + ((((color2 >> 16) & 0xFF) - ((color1 >> 16) & 0xFF)) * (i / (float)(steps - 1)));
	g = ((color1 >> 8) & 0xFF) + ((((color2 >> 8) & 0xFF) - ((color2 >> 8) & 0xFF)) * (i / (float)(steps - 1)));
	b = ((color1 & 0xFF) + (((color2 & 0xFF) - (color1 & 0xFF)) * (i / (float)(steps - 1))));
	return (r << 16 | g << 8 | b);
}

float ft_map(float value, float in_min, float in_max, float out_min, float out_max)
{
	return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
