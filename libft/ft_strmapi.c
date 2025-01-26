#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fstr;

	i = 0;
	fstr = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!fstr)
		return (NULL);
	while (s[i])
	{
		fstr[i] = f(i, s[i]);
		i++;
	}
	fstr[i] = '\0';
	return (fstr);
}
