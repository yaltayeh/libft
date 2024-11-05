/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 00:47:34 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/06 01:17:34 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_search(t_stack *stack, t_data data, t_node **res)
{
	t_node	*head;
	int		test;

	if (!stack)
		return (-1);
	test = 0;
	*res = NULL;
	head = stack->head;
	while (head)
	{
		if (ft_cmp_data(stack, head->data, data, &test))
			return (-1);
		if (!test)
		{
			*res = head;
			return (0);
		}
		head = head->next;
	}
	return (0);
}
