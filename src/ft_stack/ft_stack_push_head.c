#include "ft_stack.h"

void	ft_stack_head_push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->parent = stack;
	node->next = stack->head;
	if (stack->head)
		stack->head->prev = node;
	stack->head = node;
	while (stack->head->prev)
		stack->head = stack->head->prev;
	if (!stack->tail)
	{
		stack->tail = node;
		while (stack->tail->next)
			stack->tail = stack->tail->next;
	}
}