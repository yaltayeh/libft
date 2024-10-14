/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaltayeh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/26 20:46:41 by yaltayeh		  #+#	#+#			 */
/*   Updated: 2024/08/29 11:59:20 by yaltayeh         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_count(int n, int base)
{
	int	count;

	count = 0;
	if (base < 2)
		return (-1);
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n, int with_sign)
{
	char	*ret;
	int		digit_count;
	long	num;

	digit_count = get_digit_count(n, 10) + !!with_sign;
	ret = ft_calloc(digit_count + 1, sizeof(char));
	if (!ret)
		return (NULL);
	num = n;
	if (num < 0)
	{
		num *= -1;
		if (with_sign)
			ret[0] = '-';
	}
	if (num == 0)
		ret[0] = '0';
	while (num)
	{
		ret[--digit_count] = '0' + (num % 10);
		num /= 10;
	}
	return (ret);
}
