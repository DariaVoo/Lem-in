#include "lemin.h"

// word_counter
int	ft_word_counter(char const *s, char c)
{
	int	q;

	q = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			q++;
		s++;
	}
	return (q);
}

void	**ft_free(void **mas, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(mas[i]);
		mas[i] = NULL;
		i++;
	}
	free(mas);
	mas = NULL;
	return (mas);
}