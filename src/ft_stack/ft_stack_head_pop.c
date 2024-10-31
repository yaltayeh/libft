#include "ft_stack.h"

t_node	*ft_stack_head_pop(t_stack *stack)
{
	t_node	*node;

	node = NULL;
	if (!stack)
		return (node);
	node = stack->head;
	if (node)
	{
		stack->head = node->next;
		if (stack->head)
			stack->head->prev = NULL;
		node->parent = NULL;
		node->next = NULL;
		node->prev = NULL;
	}
	if (stack->tail == node)
		stack->tail = NULL;
	return (node);
}