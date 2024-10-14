/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:25:15 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/14 00:25:16 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hex_helper(unsigned int u32, size_t *count, \
							size_t *numbers, t_flags flags)
{
	if (flags & ZERO)
		*count += ft_zero_apply(numbers[0], *count);
	if (flags & DOT)
		*count += ft_zero_apply(numbers[1], *count);
	if (flags & SHARP && u32)
		*count += 2;
	if (flags & NUMBER && !(flags & (DOT | ZERO)))
		*count += ft_blank_apply(numbers[0], *count);
}

size_t	ft_hex_handle(unsigned int u32, t_flags flags, \
						size_t *numbers, int upper)
{
	char	*hex;
	size_t	count;
	size_t	len;

	count = 0;
	if (upper)
		hex = ft_itoa_base(u32, HEX_BASE_UPPER);
	else
		hex = ft_itoa_base(u32, HEX_BASE);
	len = ft_strlen(hex);
	count += len;
	ft_hex_helper(u32, &count, numbers, flags);
	if (flags & SHARP && u32)
		ft_sharp_apply(upper);
	ft_putstr(hex);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[0], count);
	free(hex);
	return (count);
}

size_t	ft_percent_handle(void)
{
	ft_putchar('%');
	return (1);
}
