#include "fdf.h"

float toIso_x(t_cord* c)
{
	return (c->x - c->y);
}

float toIso_y(t_cord* c)
{
	return ((c->x + c->y) / 2 - c->z);
}
