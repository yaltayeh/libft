/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:37:57 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/05 22:52:06 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char    **ft_split_iter(char const *s, char c, int i)
{
	char		*p;
	char		**slices;
	char		*slice;

	while (*s == c)
		s++;
	p = s;
	while (*s && *s != c)
		s++;
	if (s == p)
		return (ft_calloc(i + 1, sizeof(char *)));
	p = ft_substr(p, 0, s - p);
	if (!slice)
		return (NULL);
	slices = ft_split_iter(s, c, i + 1);
	if (!slices)
	{
		free(slice);
		return (NULL);
	}
	slices[i] = slice;
	return (slices);
}

char    **ft_split(char const *s, char c)
{
	return (ft_split_iter(s, c, 0));
}
