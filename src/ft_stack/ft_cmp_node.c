/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:49:10 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/06 01:13:37 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_cmp_data(t_stack *stack, t_data data1, t_data data2, int *res)
{
	t_func_ptr	cmp_fn;
	int			err;

	err = 0;
	cmp_fn = stack->cmp_fn;
	if (stack->data_type == FT_W0)
		*res = cmp_fn.cmp_w0(data1.i32, data2.i32, &err);
	else if (stack->data_type == FT_X0)
		*res = cmp_fn.cmp_x0(data1.ptr, data2.ptr, &err);
	else if (stack->data_type == FT_S0)
		*res = cmp_fn.cmp_s0(data1.f32, data2.f32, &err);
	else if (stack->data_type == FT_D0)
		*res = cmp_fn.cmp_d0(data1.d64, data2.d64, &err);
	else
		err = -1;
	return (err);
}

int	ft_cmp_node(t_node *node1, t_node *node2, int *res)
{
	t_stack		*parent1;
	t_stack		*parent2;

	if (!node1 || !node2)
		return (-1);
	parent1 = node1->parent;
	parent2 = node2->parent;
	if (!parent1 || !parent2 || (parent1->cmp_fn.ptr != parent2->cmp_fn.ptr) \
		|| (parent1->data_type != parent2->data_type))
		return (-1);
	return (ft_cmp_data(parent1, node1->data, node2->data, res));
}
