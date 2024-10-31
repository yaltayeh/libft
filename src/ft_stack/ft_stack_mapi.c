#include "ft_stack.h"

t_stack	*ft_stack_mapi(t_stack *stack, void (*f)())
{
	t_stack		*new_stack;
	int			err;

	new_stack = ft_stack_copy(stack);
	if (!new_stack)
		return (NULL);
	err = ft_stack_head_iter(new_stack, f);
	if (err != 0)
	{
		ft_stack_clear(&new_stack);
		return (NULL);
	}
	return (new_stack);
}