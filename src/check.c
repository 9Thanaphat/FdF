/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:12:31 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/25 22:25:50 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_valid(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!(((num[0] == '+' || num[0] == '-') && ft_isdigit(num[1]))
				|| ft_isdigit(num[i])))
			return (-1);
		i++;
	}
	return (0);
}
