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

int	ft_vfprintf(va_list	va, int fd, const char *fmt)
{
	int				count;
	t_printf_data	data;

	ft_bzero(&data, sizeof(data));
	data.va = &va;
	data.fd = fd;
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			data.flags = ft_flags_parser(&fmt, data.numbers, NONE);
			if (ft_strchr(CONVENTIONS_CHARACTERS, *fmt))
				count += ft_printf_redirect(*fmt, data);
			else
				count += ft_putchar_fd(*fmt, fd);
		}
		else
			count += ft_putchar_fd(*fmt, fd);
		fmt++;
	}
	return (count);
}
