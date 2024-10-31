#include "ft_stack.h"

t_stack	*ft_stack_mapi(t_stack *stack, t_content (*f)())
{
	size_t	i;
	t_node	*head;
	t_content	tmp;
	t_node		*node;
	t_stack		*new_stack;

	i = 0;
	head = stack->head;
	
	while (head)
	{
		tmp = stack->__f(head->content, i);
		node = ft_newnode(tmp);
		if (!node)
		{
			stack->del(tmp);
			ft_stack_clear(&);
			return (NULL);
		}
		head = head->next;
		i++;
	}

}
