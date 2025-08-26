/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:52:21 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/05 22:53:53 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char	*str = "1 1 1.   2 3 33333.      44444         5555 5 5 5 55 55 5 5 0 0 0 0 0 000 0 0 0 0";
	
	char **slices = ft_split(str, ' ');
	
	size_t	i;
	i = 0;
	while (slices[i])
	{
		printf("%zu: %s\n", i, slices[i]);
		free(slices[i]);
		i++;
	}
	free(slices);
	return (1);
}