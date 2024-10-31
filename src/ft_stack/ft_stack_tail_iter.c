#include "ft_stack.h"

int	ft_stack_tail_iter(t_stack *stack, void (*f)())
{
	t_node	*tail;
	size_t	i;
	int		err;
	void	(*_f)(t_data_type, size_t, int *);

	tail = stack->tail;
	_f = f;
	i = 0;
	while (tail)
	{
		err = 0;
		_f(tail->data, i, &err);
		if (err != 0)
			return (err);
		tail = tail->prev;
		i++;
	}
	return (0);
}