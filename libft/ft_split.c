#include "libft.h"

int	count_word(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		    word++;
		while (s[i] != c && s[i])
			i++;
	}
	return (word);

}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word;
	int		i;
	int		j;
	int		len;

	word = count_word(s, c);
	split = malloc(sizeof(char*) * (word + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word)
	{
		while (s[j] == c)
			j++;
		len = 0;
		while (s[j + len] != c && s[j + len])
			len++;
		split[i] = ft_substr(s, j, len);
		j += len;
		i++;
	}
	split[i] = NULL;
	return (split);
}
