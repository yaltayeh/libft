#include "ft_stack.h"

t_stack	*ft_init_stack(int	(*cmp)(), void *(*copy)(), void (*del)())
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->cmp = cmp;
	stack->copy = copy;
	stack->del = del;
	return (stack);
}