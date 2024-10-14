/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:54:29 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 19:55:41 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_redirect(va_list *ap, char conversions, \
						t_flags flags, size_t *numbers)
{
	if (conversions == 'c')
		return (ft_char_handle((char)va_arg(*ap, int), flags, numbers));
	else if (conversions == 's')
		return (ft_str_handle(va_arg(*ap, char *), flags, numbers));
	else if (conversions == 'p')
		return (ft_pointer_handle((unsigned long)va_arg(*ap, void *), \
								flags, numbers));
	else if (conversions == 'd' || conversions == 'i')
		return (ft_decimal_handle(va_arg(*ap, int), \
								flags, numbers));
	else if (conversions == 'x')
		return (ft_hex_handle(va_arg(*ap, unsigned int), \
								flags, numbers, 0));
	else if (conversions == 'X')
		return (ft_hex_handle(va_arg(*ap, unsigned int), \
								flags, numbers, 1));
	else if (conversions == 'u')
		return (ft_u_decimal_handle(va_arg(*ap, unsigned int), \
								flags, numbers));
	else if (conversions == '%')
		return (ft_percent_handle());
	return (0);
}
