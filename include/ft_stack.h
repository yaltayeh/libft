#ifndef FT_STACK_H
# define FT_STACK_H

# include "ft_linked_list.h"
# include "libft.h"

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				(*cmp)();
	void			*(*copy)();
	void			(*del)();
	t_content 		(*__f)(t_content, size_t);

}	t_stack;

t_stack	*ft_init_stack(int	(*cmp)(), void *(*copy)(), void (*del)());

void	ft_stack_head_push(t_stack *stack, t_node *node);
void	ft_stack_tail_push(t_stack *stack, t_node *node);

t_node	*ft_stack_head_pop(t_stack *stack);
t_node	*ft_stack_tail_pop(t_stack *stack);

void	ft_stack_head_iter(t_stack *stack, void (*f)());
void	ft_stack_tail_iter(t_stack *stack, void (*f)());

t_stack	*ft_stack_copy(t_stack *stack);
t_stack	*ft_stack_copy_reverse(t_stack *stack);

t_stack	*ft_stack_mapi(t_stack *stack, t_content (*f)());

t_node	*ft_stack_search(t_stack *stack, t_content content);

void	ft_stack_delnode(t_stack *node);
void	ft_stack_clear(t_stack **stack);

#endif