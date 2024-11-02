/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:36:08 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 08:29:12 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <stdio.h>

typedef struct
{
	char	name[16];
	int		age;
} t_student;


t_student	*copy_sudent(t_student *student, size_t i, int *err)
{
	t_student *new_student;

	(void)i;
	if (!student)
		return (NULL);
	new_student = malloc(sizeof(t_student));
	if (!new_student)
	{
		*err = -1;
		return (NULL);
	}
	return (new_student);
}

float	add_multi_0_5(float num)
{
	return (num * 0.5f);
}

void print_item(float value, size_t i)
{
	printf("%.3f, ", value);
	if ((i + 1) % 20 == 0)
		printf("\n");
}

int main()
{
	t_stack	*stack1;
	t_stack	*stack2;
	t_node	*node;

	stack1 = ft_init_stack(FT_FLOAT, NULL, add_multi_0_5, NULL);
	for (float i = 0; i < 50; i += 1.3)
	{
		node = ft_init_node((t_data)i);
		ft_stack_tail_push(stack1, node);
	}
	ft_stack_head_iter(stack1, print_item);
	
	printf("\n=============================\n");
	stack2 = ft_stack_copy(stack1);
	ft_stack_head_iter(stack2, print_item);
	printf("\n=============================\n");

	ft_stack_clear(&stack1);
	ft_stack_clear(&stack2);
}