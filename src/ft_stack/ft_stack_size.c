/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:42:07 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 11:11:53 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	ft_stack_size(t_stack *stack)
{
	size_t	len;
	t_node	*cur;

	len = 0;
	if (!stack)
		return (0);
	cur = stack->head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}
