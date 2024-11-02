/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:36:08 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 07:48:04 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

typedef struct
{
	char	name[16];
	int		age;
} t_student;


t_student	*add_10(t_student *student, size_t i, int *err)
{
	t_student *new_student;

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

int print_item(int value, size_t i)
{
	ft_printf("%3d, ", value);
	if ((i + 1) % 20 == 0)
		ft_printf("\n");
	return (0);
}

int main()
{
	t_stack	*stack1;
	t_stack	*stack2;
	t_node	*node;

	stack1 = ft_init_stack(FT_INT, NULL, add_10, NULL);
	for (int i = 0; i < 50; i++)
	{
		node = ft_init_node((t_data)i);
		ft_stack_tail_push(stack1, node);
	}
	ft_stack_head_iter(stack1, print_item);
	
	ft_printf("\n=============================\n");
	stack2 = ft_stack_copy(stack1);
	ft_stack_head_iter(stack2, print_item);
	ft_printf("\n=============================\n");

	ft_stack_clear(&stack1);
	ft_stack_clear(&stack2);
}