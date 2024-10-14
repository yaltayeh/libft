/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:27:29 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/08/28 12:28:52 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	min_size_t(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;
	size_t	r_len;

	s_len = ft_strlen(s);
	if (!s_len || !len || start > s_len - 1)
	{
		ret = malloc(1);
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	r_len = min_size_t(len, s_len - start);
	ret = malloc(++r_len);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, r_len);
	return (ret);
}
