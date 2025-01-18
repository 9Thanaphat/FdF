/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:01:56 by ttangcha          #+#    #+#             */
/*   Updated: 2024/09/29 13:01:58 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_check_format(va_list args, const char format);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_nbr(int num);
int	ft_print_int(int num);
int	ft_print_unsigned_int(unsigned int num);
int	ft_print_hex_lower(unsigned int num);
int	ft_print_hex_upper(unsigned int num);
int	ft_print_percent(void);
#endif
