/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_tail_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:42:15 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 11:11:18 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_tail_push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->parent = stack;
	node->prev = stack->tail;
	if (stack->tail)
		stack->tail->next = node;
	stack->tail = node;
	while (stack->tail->next)
		stack->tail = stack->tail->next;
	if (!stack->head)
	{
		stack->head = node;
		while (stack->head->prev)
			stack->head = stack->head->prev;
	}
}
