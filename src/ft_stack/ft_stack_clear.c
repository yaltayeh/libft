/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:38 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 11:11:27 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_clear(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	while ((*stack)->head)
	{
		(*stack)->head->parent = *stack;
		ft_stack_delnode((*stack)->head);
	}
	free(*stack);
	*stack = NULL;
}
