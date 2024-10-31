#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>

typedef union u_data_type
{
	void 			*ptr;
	long 			i64;
	int				i32;
	short			i16;
	char			i8;
	unsigned long	u64;
	unsigned int	u32;
	unsigned short	u16;
	unsigned char	u8;
}	t_data_type;

typedef struct s_node
{
	t_data_type		data;
	void			(*del)(t_data_type);
	void			*parent;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				(*cmp)();
	t_data_type		(*copy)(t_data_type);

}	t_stack;

t_node	*ft_init_node(t_data_type data, void (*del)());

t_stack	*ft_init_stack(int (*cmp)(), t_data_type (*copy)());

void	ft_stack_head_push(t_stack *stack, t_node *node);
void	ft_stack_tail_push(t_stack *stack, t_node *node);

t_node	*ft_stack_head_pop(t_stack *stack);
t_node	*ft_stack_tail_pop(t_stack *stack);

int		ft_stack_head_iter(t_stack *stack, void (*f)());
int		ft_stack_tail_iter(t_stack *stack, void (*f)());

t_stack	*ft_stack_copy(t_stack *stack);
t_stack	*ft_stack_copy_reverse(t_stack *stack);

t_stack	*ft_stack_mapi(t_stack *stack, void (*f)());

void	ft_stack_delnode(t_node *node);
void	ft_stack_clear(t_stack **stack);

#endif