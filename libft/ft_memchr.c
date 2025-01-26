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
