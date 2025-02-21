/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:19:57 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 13:19:58 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	if (!dest && !src)
		return (dest);
	ptrd = (unsigned char *)dest;
	ptrs = (unsigned char *)src;
	while (n)
	{
		*ptrd++ = *ptrs++;
		n--;
	}
	return (dest);
}
