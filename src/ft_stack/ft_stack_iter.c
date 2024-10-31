#include "ft_stack.h"

void	ft_stack_head_iter(t_stack *stack, void (*f)())
{
	t_node	*head;
	size_t	i;
	void	(*_f)(t_content, size_t);

	head = stack->head;
	_f = f;
	i = 0;
	while (head)
	{
		_f(head->content, i);
		head = head->next;
		i++;
	}
}

void	ft_stack_tail_iter(t_stack *stack, void (*f)())
{
	t_node	*tail;
	size_t	i;
	void	(*_f)(t_content, size_t);

	tail = stack->tail;
	_f = f;
	i = 0;
	while (tail)
	{
		_f(tail->content, i);
		tail = tail->prev;
		i++;
	}
}