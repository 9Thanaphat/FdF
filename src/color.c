/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:08:25 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/22 07:18:02 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	hex_to_int(const char *str)
{
	int	result;
	int	sign;
	int	value;
	int	i;

	result = 0;
	sign = 1;
	str += 2;
	i = 0;
	while (str[i])
	{
		value = chartonum(str[i]);
		result = result * 16 + value;
		str++;
	}
	return (result * sign);
}
