/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaltayeh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/08 19:50:37 by yaltayeh		  #+#	#+#			 */
/*   Updated: 2024/09/08 19:52:35 by yaltayeh         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	enum e_flags	flags;
	va_list			ap;
	int				count;
	size_t			numbers[2];

	va_start(ap, fmt);
	flags = NONE;
	count = 0;
	ft_bzero(numbers, sizeof(numbers));
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			flags = ft_flags_parser(&fmt, numbers, NONE);
			if (ft_strchr(CONVENTIONS_CHARACTERS, *fmt))
				count += ft_printf_redirect(&ap, *fmt, flags, numbers);
			else
				count += ft_putchar(*fmt);
		}
		else
			count += ft_putchar(*fmt);
		fmt++;
	}
	return (count);
}
