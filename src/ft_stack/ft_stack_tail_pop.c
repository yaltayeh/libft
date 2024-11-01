/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_tail_pop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:42:13 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 00:42:14 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_node	*ft_stack_tail_pop(t_stack *stack)
{
	t_node	*node;

	node = NULL;
	if (!stack)
		return (node);
	node = stack->tail;
	if (node)
	{
		stack->tail = node->prev;
		if (stack->tail)
			stack->tail->next = NULL;
		node->parent = NULL;
		node->next = NULL;
		node->prev = NULL;
	}
	if (stack->head == node)
		stack->head = NULL;
	return (node);
}
