/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:32 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 11:13:29 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_init_stack(int data_type, void *cmp_fn, \
						void *copy_fn, void *del_fn)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->data_type = data_type;
	stack->cmp_fn = (t_func_ptr)cmp_fn;
	stack->copy_fn = (t_func_ptr)copy_fn;
	stack->del_fn = (t_func_ptr)del_fn;
	return (stack);
}
