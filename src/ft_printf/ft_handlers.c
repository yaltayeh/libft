/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:25:04 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/14 00:25:05 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_char_handle(char c, t_flags flags, size_t *numbers)
{
	size_t	count;

	count = 0;
	if (flags & NUMBER && !(flags & MINUS))
		count += ft_blank_apply(numbers[0], 1);
	write(1, &c, 1);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[0], 1);
	return (count + 1);
}

size_t	ft_str_handle(char *s, t_flags flags, size_t *numbers)
{
	size_t	count;
	size_t	len;

	count = 0;
	if (!s)
	{
		s = "(null)";
		if (numbers[1] < 6)
			numbers[1] = 0;
	}
	len = ft_strlen(s);
	if (flags & DOT && len > numbers[1])
		len = numbers[1];
	count += len;
	if (flags & (NUMBER | ZERO) && !(flags & MINUS))
		count += ft_blank_apply(numbers[0], count);
	write(1, s, len);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[0], count);
	return (count);
}

size_t	ft_pointer_handle(unsigned long addr, t_flags flags, size_t *numbers)
{
	char			*hex;
	char			*str;
	size_t			count;

	if (!addr)
		str = "(nil)";
	else
	{
		hex = ft_itoa_base(addr, HEX_BASE);
		if (!hex)
			return (0);
		str = ft_strjoin("0x", hex);
		free(hex);
		if (!str)
			return (0);
	}
	count = ft_strlen(str);
	if (flags & NUMBER && !(flags & MINUS))
		count += ft_blank_apply(numbers[0], count);
	ft_putstr(str);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[0], count);
	if (addr)
		free(str);
	return (count);
}
