/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:24:41 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/14 00:24:42 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_sharp_apply(int upper)
{
	if (upper)
		ft_putstr("0X");
	else
		ft_putstr("0x");
	return (2);
}

size_t	ft_zero_apply(size_t num, size_t count)
{
	size_t	i;

	i = 0;
	while (num > count + i)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

size_t	ft_blank_apply(size_t num, size_t count)
{
	size_t	i;

	i = 0;
	while (num > count + i)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
