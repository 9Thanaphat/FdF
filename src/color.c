/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:08:25 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 13:16:45 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	chartonum(char c)
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
	int	i;
	int	r;
	int	g;
	int	b;

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

int	ft_gradient(int c1, int c2, int per)
{
	int	r;
	int	g;
	int	b;

	r = ((c1 >> 16) & 0xFF) + ((((c2 >> 16) & 0xFF)
				- ((c1 >> 16) & 0xFF)) * per / 100);
	g = ((c1 >> 8) & 0xFF) + ((((c2 >> 8) & 0xFF)
				- ((c1 >> 8) & 0xFF)) * per / 100);
	b = ((c1 & 0xFF) + (((c2 & 0xFF) - (c1 & 0xFF)) * per / 100));
	return (r << 16 | g << 8 | b);
}
