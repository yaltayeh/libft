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

int	ft_fprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int 	ret;

	va_start(ap, fmt);
	ret = ft_vfprintf(fd, fmt, &ap);
	va_end(ap);
	return (ret);
}
