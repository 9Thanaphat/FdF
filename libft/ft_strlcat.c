#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	srcsize;
	size_t	i;
	size_t	j;

	j = ft_strlen(dst);
	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (size <= dstsize)
		return (size + srcsize);
	i = 0;
	while (src[i] != '\0' && (dstsize + 1) < size)
	{
		dst[dstsize] = src[i];
		i++;
		dstsize++;
	}
	dst[dstsize] = '\0';
	return (j + srcsize);
}
