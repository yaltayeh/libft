/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fn_caller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:42 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 08:25:57 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_data	ft_stack_fn_caller(void *fn, int in_type, t_data in_data, size_t i, int *err)
{
	t_data		out_data;
	t_func_ptr	fn_ptr;

	*err = 0;
	fn_ptr.ptr = fn;
	out_data.ptr = NULL;
	if (in_type == FT_W0)
		out_data.i32 = fn_ptr.w0(in_data.i32, i, err);
	else if (in_type == FT_X0)
		out_data.ptr = fn_ptr.x0(in_data.ptr, i, err);
	else if (in_type == FT_S0)
		out_data.f32 = fn_ptr.s0(in_data.f32, i, err);
	else if (in_type == FT_D0)
		out_data.d64 = fn_ptr.d0(in_data.d64, i, err);
	else
		*err = -1;
	return (out_data);
}