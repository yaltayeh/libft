#include "ft_stack.h"

int	ft_stack_head_iter(t_stack *stack, void (*f)())
{
	t_node	*head;
	size_t	i;
	int		err;
	void	(*_f)(t_data_type, size_t, int *);

	head = stack->head;
	_f = f;
	i = 0;
	while (head)
	{
		err = 0;
		_f(head->data, i, &err);
		if (err != 0)
			return (err);
		head = head->next;
		i++;
	}
	return (0);
}