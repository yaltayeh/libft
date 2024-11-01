/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_copy_fn_caller.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:41:42 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 00:41:44 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_data	ft_stack_copy_fn_caller(t_stack *stack, t_data data, size_t i, int *err)
{
	int		(*get_w0)();
	void	*(*get_x0)();
	t_data	res;

	*err = 0;
	res.ptr = NULL;
	if (stack->data_type == FT_W0)
	{
		get_w0 = stack->copy_fn;
		ft_inject_data_w0(data.i32, i, err);
		res.i32 = get_w0();
	}
	else if (stack->data_type == FT_X0)
	{
		get_x0 = stack->copy_fn;
		ft_inject_data_x0(data.ptr, i, err);
		res.ptr = get_x0();
	}
	else
		*err = -1;
	return (res);
}