/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:50 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 11:14:07 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static int	ft_add_new_node(t_stack *stack, t_node *cur)
{
	t_data	new_data;
	t_node	*new_node;

	if (!stack || !cur)
		return (0);
	stack->err = 0;
	new_data = ft_stack_fn_caller(stack, cur, stack->copy_fn.ptr);
	if (stack->err != 0)
	{
		if (stack->del_fn.ptr)
			ft_stack_fn_caller(stack, cur, stack->del_fn.ptr);
		return (stack->err);
	}
	new_node = ft_init_node(new_data);
	if (!new_node)
	{
		stack->err = -1;
		if (stack->del_fn.ptr)
			ft_stack_fn_caller(stack, cur, stack->del_fn.ptr);
		return (stack->err);
	}
	ft_stack_tail_push(stack, new_node);
	return (0);
}

t_stack	*ft_stack_copy(t_stack *stack)
{
	t_node		*cur;
	t_stack		*new_stack;

	new_stack = ft_init_stack(stack->data_type, stack->cmp_fn.ptr, \
							stack->copy_fn.ptr, stack->del_fn.ptr);
	if (!new_stack)
		return (NULL);
	stack->i = 0;
	cur = stack->head;
	while (cur)
	{
		if (ft_add_new_node(new_stack, cur) != 0)
		{
			ft_stack_clear(&new_stack);
			return (NULL);
		}
		cur = cur->next;
		stack->i++;
	}
	return (new_stack);
}
