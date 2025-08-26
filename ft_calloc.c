/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:54:44 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/05 23:18:16 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	nbytes;

	nbytes = count * size;
	ptr = malloc(nbytes);
	while (nbytes >= sizeof(size_t))
	{
		*((size_t *)((char *)ptr)[nbytes]) = 0UL;
		nbytes -= sizeof(size_t);
	}
	while (i < nbytes)
	{
		i++;
	}
	
	i = 0;
	return (ptr);
}
