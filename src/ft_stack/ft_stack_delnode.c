/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_delnode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:53 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 07:16:04 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_node	*ft_stack_delnode(t_node *node)
{
	t_node	*prev;
	t_node	*next;
	t_stack	*stack;
	int	err;

	if (!node)
		return (NULL);
	prev = node->prev;
	next = node->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	err = 0;
	stack = (t_stack *)node->parent;
	if (!stack)
		return (node);
	if (stack->del_fn.ptr)
		ft_stack_fn_caller(stack->del_fn.ptr, \
			stack->data_type, node->data, 0, &err);
	if (node == stack->head)
		stack->head = next;
	if (node == stack->tail)
		stack->tail = prev;
	free(node);
	return (NULL);
}