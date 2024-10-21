/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:31:00 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/08/29 12:27:44 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**init_slices(const char *s, char *delimiters)
{
	char		**slices;
	const char	*start;
	size_t		count;

	if (!s || !delimiters)
		return (NULL);
	count = 0;
	while (*s)
	{
		while (*s && ft_strchr(delimiters, *s))
			s++;
		start = s;
		while (*s && !ft_strchr(delimiters, *s))
			s++;
		if (start != s)
			count++;
	}
	slices = ft_calloc(count + 1, sizeof(char *));
	return (slices);
}

char	**ft_split(const char *s, char *delimiters)
{
	char		**slices;
	const char	*start;
	size_t		i;

	i = 0;
	slices = init_slices(s, delimiters);
	while (slices && *s)
	{
		while (*s && ft_strchr(delimiters, *s))
			s++;
		start = s;
		while (*s && !ft_strchr(delimiters, *s))
			s++;
		if (start != s)
			(void)(((slices[i++] = ft_substr(start, 0, s - start)) == NULL) && \
				({while (--i) free(slices[i]); slices = NULL;}));
	}
	return (slices);
}
