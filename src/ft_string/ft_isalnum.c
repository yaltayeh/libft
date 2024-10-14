/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaltayeh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/26 20:28:06 by yaltayeh		  #+#	#+#			 */
/*   Updated: 2024/08/27 06:57:44 by yaltayeh         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}