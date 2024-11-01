#include "ft_stack.h"

int	ft_stack_tail_iter(t_stack *stack, int (*f)())
{
	t_node	*cur;
	size_t	i;
	int		err;

	cur = stack->tail;
	i = 0;
	while (cur)
	{
		if (stack->data_type == FT_W0)
			ft_inject_data_w0(cur->data.i32, i);
		else if (stack->data_type == FT_X0)
			ft_inject_data_x0(cur->data.ptr, i);
		else
			return (-1);
		err = f();
		if (err != 0)
			return (err);
		cur = cur->prev;
		i++;
	}
	return (0);
}