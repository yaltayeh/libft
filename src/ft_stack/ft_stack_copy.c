#include "ft_stack.h"

t_stack	*ft_stack_copy(t_stack *stack)
{
	t_node	*head;
	t_node	*new_node;
	t_stack	*new_stack;

	new_stack = ft_init_stack(stack->cmp, stack->copy, stack->del);
	head = stack->head;
	while (head)
	{
		new_node = stack->copy(head->content);	
		head = head->next;
	}
	
}