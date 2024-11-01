/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaltayeh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/26 20:54:35 by yaltayeh		  #+#	#+#			 */
/*   Updated: 2024/09/08 20:09:30 by yaltayeh         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	add_check_overflow(int	*res, int a, int b)
{
	if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
		return (-1);
	*res = a + b;
	return (0);
}

static int	multi_check_overflow(int *res, int a, int b)
{
	if ((a < 0 && b == INT_MIN) || (b < 0 && a == INT_MIN))
		return (-1);
	if (b != 0 && (a > INT_MAX / b || a < INT_MIN / b))
		return (-1);
	*res = a * b;
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	ret;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	ret = 0;
	while (ft_isdigit(*nptr))
	{
		ret = ret * 10 + *nptr - '0';
		nptr++;
	}
	return (ret * sign);
}

int	ft_atoi_r(const char **p_nptr)
{
	const char	*nptr;
	int			sign;
	int			ret;

	nptr = *p_nptr;
	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	ret = 0;
	while (ft_isdigit(*nptr))
	{
		ret = ret * 10 + *nptr - '0';
		nptr++;
	}
	*p_nptr = nptr;
	return (ret * sign);
}

int	ft_atoi_save_r(const char **p_nptr, int *res)
{
	const char	*nptr;
	int			sign;
	int			num;

	nptr = *p_nptr;
	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	num = 0;
	while (ft_isdigit(*nptr))
	{
		if (multi_check_overflow(&num, num, 10))
			return (-1);
		if (add_check_overflow(&num, num, (*nptr - '0') * sign))
			return (-1);
		nptr++;
	}
	*p_nptr = nptr;
	*res = num;
	return (0);
}