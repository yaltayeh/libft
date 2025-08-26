/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:37:54 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/05 22:51:30 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *d, const char *s, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (i + 1 < dstsize)
			*d++ = s[i];
		i++;
	}
	*d = '\0';
	return (i);
}
