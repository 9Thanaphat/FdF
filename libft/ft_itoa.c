/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:19:42 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 13:19:43 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getdigits(long int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			di;
	char		*strnum;
	long int	num;

	num = n;
	di = ft_getdigits(n);
	if (num < 0)
		num *= -1;
	strnum = (char *)malloc(sizeof(char) * (di + 1));
	if (!strnum)
		return (NULL);
	*(strnum + di) = '\0';
	while (di--)
	{
		*(strnum + di) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		strnum[0] = '-';
	return (strnum);
}
