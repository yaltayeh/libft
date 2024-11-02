/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:49:10 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 22:12:51 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_cmp_node(t_node *node1, t_node *node2, int *res)
{
	t_stack		*parent1;
	t_stack		*parent2;
	t_func_ptr	cmp_fn;
	int			err;

	if (!node1 || !node2)
		return (-1);
	parent1 = node1->parent;
	parent2 = node2->parent;
	if (!parent1 || !parent2 || (parent1->cmp_fn.ptr != parent2->cmp_fn.ptr) \
		|| (parent1->data_type != parent2->data_type))
		return (-1);
	err = 0;
	cmp_fn = parent1->cmp_fn;
	if (parent1->data_type == FT_W0)
		*res = cmp_fn.cmp_w0(node1->data.i32, node2->data.i32, &err);
	else if (parent1->data_type == FT_X0)
		*res = cmp_fn.cmp_x0(node1->data.ptr, node2->data.ptr, &err);
	else if (parent1->data_type == FT_S0)
		*res = cmp_fn.cmp_s0(node1->data.f32, node2->data.f32, &err);
	else if (parent1->data_type == FT_D0)
		*res = cmp_fn.cmp_d0(node1->data.d64, node2->data.d64, &err);
	else
		err = -1;
	return (err);
}
