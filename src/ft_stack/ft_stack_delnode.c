/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_delnode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:53 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 00:41:55 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_delnode(t_node *node)
{
	t_node	*prev;
	t_node	*next;
	t_stack	*stack;

	if (!node)
		return ;
	prev = node->prev;
	next = node->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	if (node->del)
		node->del(node->data);
	stack = (t_stack *)node->parent;
	if (stack)
	{
		if (node == stack->head)
			stack->head = next;
		if (node == stack->tail)
			stack->tail = prev;
	}
	free(node);
}