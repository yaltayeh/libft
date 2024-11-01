#include "ft_stack.h"

int	ft_stack_head_iter(t_stack *stack, int (*f)())
{
	t_node	*cur;
	size_t	i;
	int		err;

	cur = stack->head;
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
		cur = cur->next;
		i++;
	}
	return (0);
}