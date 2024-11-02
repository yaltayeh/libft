/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_copy_reverse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:45 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 07:44:39 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static int ft_add_new_node(t_stack *stack, t_node *cur, size_t i)
{
	int		err;
	t_data	new_data;
	t_node	*new_node;

	if (!stack || !cur)
		return (0);
	err = 0;
	new_data = ft_stack_fn_caller(stack->copy_fn.ptr, stack->data_type, cur->data, i, &err);
	if (err != 0)
	{
		if (stack->del_fn.ptr)
			ft_stack_fn_caller(stack->del_fn.ptr, stack->data_type, new_data, i, &err);
		return (err);
	}
	new_node = ft_init_node(new_data);
	if (!new_node)
	{
		err = -1;
		if (stack->del_fn.ptr)
			ft_stack_fn_caller(stack->del_fn.ptr, stack->data_type, new_data, i, &err);
		return (err);
	}
	ft_stack_tail_push(stack, new_node);
	return (0);
}

t_stack	*ft_stack_copy_reverse(t_stack *stack)
{
	t_node		*cur;
	t_stack		*new_stack;
	size_t		i;

	new_stack = ft_init_stack(stack->data_type, stack->cmp_fn.ptr, stack->copy_fn.ptr, stack->del_fn.ptr);
	if (!new_stack)
		return (NULL);
	i = 0;
	cur = stack->tail;
	while (cur)
	{
		if (ft_add_new_node(new_stack, cur, i) != 0)
		{
			ft_stack_clear(&new_stack);
			return (NULL);
		}
		cur = cur->prev;
	}
	return (new_stack);
}
