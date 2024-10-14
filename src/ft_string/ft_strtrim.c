/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:27:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/08/28 13:14:24 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	const char	*lptr;
	const char	*rptr;
	size_t		len;

	lptr = s1;
	rptr = s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *lptr) && *lptr)
		lptr++;
	while (ft_strchr(set, *rptr) && *rptr)
		rptr--;
	if (rptr < lptr)
		return (ft_strdup("\0"));
	len = rptr - lptr + 1;
	ret = malloc(++len);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, lptr, len);
	return (ret);
}
