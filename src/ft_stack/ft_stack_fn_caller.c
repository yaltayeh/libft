/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fn_caller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:42 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 11:12:55 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_data	ft_stack_fn_caller(t_stack *stack, t_node *node, void *fn)
{
	t_data		out_data;
	t_func_ptr	fn_ptr;

	stack->err = 0;
	fn_ptr.ptr = fn;
	out_data.ptr = NULL;
	if (stack->data_type == FT_W0)
		out_data.i32 = fn_ptr.w0(node->data.i32, stack->i, &stack->err);
	else if (stack->data_type == FT_X0)
		out_data.ptr = fn_ptr.x0(node->data.ptr, stack->i, &stack->err);
	else if (stack->data_type == FT_S0)
		out_data.f32 = fn_ptr.s0(node->data.f32, stack->i, &stack->err);
	else if (stack->data_type == FT_D0)
		out_data.d64 = fn_ptr.d0(node->data.d64, stack->i, &stack->err);
	else
		stack->err = -1;
	return (out_data);
}
