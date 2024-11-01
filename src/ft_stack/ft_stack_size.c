#include "ft_stack.h"

size_t	ft_stack_size(t_stack *stack)
{
	size_t	len;
	t_node	*cur;

	len = 0;
	if (!stack)
		return (0);
	cur = stack->head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}