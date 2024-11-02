/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_tail_iter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:42:10 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 01:14:48 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_tail_iter(t_stack *stack, void *f)
{
	t_node	*cur;
	size_t	i;
	int		err;

	cur = stack->tail;
	i = 0;
	while (cur)
	{
		ft_stack_fn_caller(f, stack->data_type, cur->data, i, &err);
		if (err != 0)
			return (err);
		cur = cur->prev;
		i++;
	}
	return (0);
}
