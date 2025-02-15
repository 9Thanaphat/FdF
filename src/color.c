#include "fdf.h"

int chartonum(char c)
{
	if (c >= 'a' && c <= 'f')
		return ((c - 'a') + 10);
	else if (c >= 'A' && c <= 'F')
		return ((c - 'A') + 10);
	else if (c >= '0' && c <= '9')
		return (c - '0');
	else
		return (0);
}

int	to_rgb(char *s)
{
	int	t;
	int i;
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;
	i = 0;
	while (s[i])
	{
		if (i == 3)
			r = chartonum(s[2]) * 16 + chartonum(s[3]);
		if (i == 5)
			g = chartonum(s[4]) * 16 + chartonum(s[5]);
		if (i == 7)
			b = chartonum(s[6]) * 16 + chartonum(s[7]);
		i++;
	}
	return (r << 16 | g << 8 | b);
}

int ft_gradient(int color1, int color2, int percent)
{
	int	r;
	int	g;
	int	b;

	r = ((color1 >> 16) & 0xFF) + ((((color2 >> 16) & 0xFF) - ((color1 >> 16) & 0xFF)) * percent / 100);
	g = ((color1 >> 8) & 0xFF) + ((((color2 >> 8) & 0xFF) - ((color1 >> 8) & 0xFF)) * percent / 100);
	b = ((color1 & 0xFF) + (((color2 & 0xFF) - (color1 & 0xFF)) * percent / 100));
	return (r << 16 | g << 8 | b);
}
