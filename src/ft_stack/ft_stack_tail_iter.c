/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_tail_iter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:42:10 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 11:02:43 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_tail_iter(t_stack *stack, void *f)
{
	t_node	*cur;

	cur = stack->tail;
	stack->i = 0;
	while (cur)
	{
		stack->err = 0;
		ft_stack_fn_caller(stack, cur, f);
		if (stack->err != 0)
			return (stack->err);
		cur = cur->prev;
		stack->i++;
	}
	return (0);
}
