/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_head_iter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:56 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 01:14:40 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_head_iter(t_stack *stack, void *f)
{
	t_node	*cur;
	size_t	i;
	int		err;

	cur = stack->head;
	i = 0;
	while (cur)
	{
		ft_stack_fn_caller(f, stack->data_type, cur->data, i, &err);
		if (err != 0)
			return (err);
		cur = cur->next;
		i++;
	}
	return (0);
}
