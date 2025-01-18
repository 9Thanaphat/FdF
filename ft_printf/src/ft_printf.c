/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:01:39 by ttangcha          #+#    #+#             */
/*   Updated: 2024/09/29 13:01:40 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_check_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd')
		len += ft_print_nbr(va_arg(args, int));
	else if (format == 'i')
		len += ft_print_int(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	len;

	va_list(args);
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check_format(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len += 1;
		}
		i++;
	}
	va_end(args);
	return (len);
}
