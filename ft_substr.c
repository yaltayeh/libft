/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:38:00 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/05 22:52:01 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = 0;
	while (s[i] && size < len)
	{
		if (i >= start)
			size++;
		i++;
	}
	sub = malloc(size + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, size + 1);
	return (sub);
}
