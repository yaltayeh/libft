#include "ft_stack.h"

t_stack	*ft_init_stack(int (*cmp)(), t_data_type (*copy)())
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->cmp = cmp;
	stack->copy = copy;
	return (stack);
}