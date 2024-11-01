#include "ft_stack.h"

t_stack	*ft_init_stack(int data_type, int (*cmp)(), t_data (*copy)())
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->data_type = data_type;
	stack->cmp = cmp;
	stack->copy = copy;
	return (stack);
}