/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:45:03 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 00:45:05 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcheck(const char *str, int (*f)(int))
{
	if (!str || !f)
		return (-1);
	while (*str)
	{
		if (!f(*str))
			return (0);
		str++;
	}
	return (1);
}