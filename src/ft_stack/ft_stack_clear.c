#include "ft_stack.h"

void	ft_stack_clear(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	
	while ((*stack)->head)
		ft_stack_delnode((*stack)->head);
	free(*stack);
	*stack = NULL;
}