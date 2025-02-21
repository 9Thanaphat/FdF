/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:19:46 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 13:19:47 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (void *)s;
	while (n)
	{
		if (*ptr == (char) c)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
