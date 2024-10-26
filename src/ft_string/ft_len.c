#include "libft.h"

size_t	ft_len(const void **lst)
{
	size_t	i;

	i = 0;
	while (lst[i])
		i++;
	return (i);
}