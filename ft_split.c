#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

char    **ft_split(char const *s, char c)
{
	static int	i;
	char		*p;
	char		**slices;

	while (*s == c)
		s++;
	p = s;
	while (*s && *s != c)
		s++;
	
	slices = ft_split(s, c);
}