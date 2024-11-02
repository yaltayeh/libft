/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_head_iter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:56 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 11:01:21 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_head_iter(t_stack *stack, void *f)
{
	t_node	*cur;
	size_t	i;

	cur = stack->head;
	i = 0;
	while (cur)
	{
		stack->i = i;
		ft_stack_fn_caller(stack, cur, f);
		if (stack->err != 0)
			return (stack->err);
		cur = cur->next;
		i++;
	}
	return (0);
}
