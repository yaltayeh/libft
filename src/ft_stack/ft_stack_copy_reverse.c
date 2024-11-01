#include "ft_stack.h"

t_stack	*ft_stack_copy_reverse(t_stack *stack)
{
	t_node		*cur;
	t_node		*new_node;
	t_stack		*new_stack;
	t_data	new_content;

	if (!stack)
		return (NULL);
	new_stack = ft_init_stack(stack->data_type, stack->cmp, stack->copy);
	if (!new_stack)
		return (NULL);
	cur = stack->head;
	while (cur)
	{
		new_content = stack->copy(cur->data);
		new_node = ft_init_node(new_content, cur->del);
		if (!new_node)
		{
			if (cur->del)
				cur->del(new_content);
			ft_stack_clear(&new_stack);
			return (NULL);
		}
		ft_stack_head_push(new_stack, new_node);
		cur = cur->next;
	}
	return (new_stack);
}
