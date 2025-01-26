#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	s;

	s = (size_t)(nmemb * size);
	if ((long)nmemb == 0 || (long)size == 0)
		s = 0;
	else if ((long)nmemb < 0 || (long)size < 0)
		return (NULL);
	ptr = malloc(s);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, s);
	return (ptr);
}
