/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:01:00 by ttangcha          #+#    #+#             */
/*   Updated: 2024/09/29 13:01:01 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_nbr(int num)
{
	char	*str;
	int		len;

	str = ft_itoa(num);
	len = (int)ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
