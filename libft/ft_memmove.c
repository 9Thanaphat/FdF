#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrd;
	const unsigned char	*ptrs;

	if (!dest && !src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	ptrd = (unsigned char *)dest;
	ptrs = (unsigned char *)src;
	while (n--)
	{
		ptrd[n] = ptrs[n];
	}
	return (dest);
}
