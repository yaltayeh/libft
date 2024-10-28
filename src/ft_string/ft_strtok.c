#include "libft.h"

char	*ft_strtok(char *s, const char *d)
{
	static char	*old;
	char		*start;

	start = NULL;
	if (!s)
		s = old;
	if (!s)
		return (NULL);
	while (*s && ft_strchr(d, *s))
		s++;
	start = s;
	while (*s && !ft_strchr(d, *s))
		s++;
	if (s == start)
		return (NULL);
	else if (*s == '\0')
		old = NULL;
	else
	{
		*s = '\0';
		old = s + 1;
	}
	return (start);
}