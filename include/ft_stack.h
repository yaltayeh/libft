#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>

#define FT_W0		(1 << 8)
#define FT_X0		(2 << 8)

#define FT_POINTER			FT_X0

#define FT_LONG				FT_X0
#define FT_INT				FT_W0
#define FT_SHORT			FT_W0
#define FT_CHAR				FT_W0

#define FT_UNSIGNED_LONG	FT_X0
#define FT_UNSIGNED_INT		FT_W0
#define FT_UNSIGNED_SHORT	FT_W0
#define FT_UNSIGNED_CHAR	FT_W0

typedef union u_data
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
}	t_data;

typedef struct s_node
{
	t_data		data;
	void			(*del)(t_data);
	void			*parent;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				data_type;
	int				(*cmp)();
	t_data			(*copy)(t_data);
}	t_stack;

t_node	*ft_init_node(t_data data, void (*del)());

t_stack	*ft_init_stack(int data_type, int (*cmp)(), t_data (*copy)());

size_t	ft_stack_size(t_stack *stack);

void	ft_stack_head_push(t_stack *stack, t_node *node);
void	ft_stack_tail_push(t_stack *stack, t_node *node);

t_node	*ft_stack_head_pop(t_stack *stack);
t_node	*ft_stack_tail_pop(t_stack *stack);

void	ft_inject_data_w0(int w0, size_t i);
void	ft_inject_data_x0(void *x0, size_t i);

int		ft_stack_head_iter(t_stack *stack, int (*f)());
int		ft_stack_tail_iter(t_stack *stack, int (*f)());

t_stack	*ft_stack_copy(t_stack *stack);
t_stack	*ft_stack_copy_reverse(t_stack *stack);

t_stack	*ft_stack_mapi(t_stack *stack, void (*f)());

void	ft_stack_delnode(t_node *node);
void	ft_stack_clear(t_stack **stack);

#endif