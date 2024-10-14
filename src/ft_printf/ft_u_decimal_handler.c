/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_decimal_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:25:28 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/14 00:26:18 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	ft_u_decimal_helper1(size_t *count, \
							size_t *numbers)
{
	size_t	blank_count;

	blank_count = ft_blank_apply(numbers[0], \
					ft_max(numbers[1], *count));
	*count += ft_zero_apply(numbers[1], *count);
	*count += blank_count;
}

static void	ft_u_decimal_helper2(size_t *count, \
								size_t *numbers, t_flags flags)
{
	if (flags & NUMBER)
		*count += ft_blank_apply(numbers[0], *count);
	if (flags & ZERO)
		*count += ft_zero_apply(numbers[0], *count);
	else if (flags & DOT)
		*count += ft_zero_apply(numbers[1], *count);
}

size_t	ft_u_decimal_handle(unsigned int u32, t_flags flags, size_t *numbers)
{
	char	*decimal;
	size_t	count;

	count = 0;
	decimal = ft_itoa_base((unsigned long)u32, DECIMAL_BASE);
	if (u32 || !(flags & DOT))
		count += ft_strlen(decimal);
	if ((flags & (ZERO | NUMBER)) && (flags & DOT))
		ft_u_decimal_helper1(&count, numbers);
	else
		ft_u_decimal_helper2(&count, numbers, flags);
	if (u32 || !(flags & DOT))
		ft_putstr(decimal);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[0], count);
	free(decimal);
	return (count);
}
