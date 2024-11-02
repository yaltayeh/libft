/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:34:51 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 07:45:51 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>

# define FT_W0		(1 << 8)
# define FT_X0		(2 << 8)

# define FT_POINTER			FT_X0

# define FT_LONG			FT_X0
# define FT_INT				FT_W0
# define FT_SHORT			FT_W0
# define FT_CHAR			FT_W0

# define FT_UNSIGNED_LONG	FT_X0
# define FT_UNSIGNED_INT	FT_W0
# define FT_UNSIGNED_SHORT	FT_W0
# define FT_UNSIGNED_CHAR	FT_W0

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

typedef	union u_func_ptr
{
	void	*ptr;
	int		(*w0)(int, size_t, int *);
	void	*(*x0)(void *, size_t, int *);
}	t_func_ptr;

typedef struct s_node
{
	t_data			data;
	void			*parent;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				data_type;
	t_func_ptr		cmp_fn;
	t_func_ptr		copy_fn;
	t_func_ptr		del_fn;
}	t_stack;

t_node	*ft_init_node(t_data data);

t_stack	*ft_init_stack(int data_type, void *cmp_fn, void *copy_fn, void *del_fn);

size_t	ft_stack_size(t_stack *stack);

t_data	ft_stack_fn_caller(void *fn, int in_type, t_data in_data, size_t i, int *err);

void	ft_stack_head_push(t_stack *stack, t_node *node);
void	ft_stack_tail_push(t_stack *stack, t_node *node);

t_node	*ft_stack_head_pop(t_stack *stack);
t_node	*ft_stack_tail_pop(t_stack *stack);

int		ft_stack_head_iter(t_stack *stack, void *fn);
int		ft_stack_tail_iter(t_stack *stack, void *fn);

t_stack	*ft_stack_copy(t_stack *stack);
t_stack	*ft_stack_copy_reverse(t_stack *stack);

t_stack	*ft_stack_mapi(t_stack *stack, void *fn);

t_node	*ft_stack_delnode(t_node *node);
void	ft_stack_clear(t_stack **stack);

void	empty_fn(void);

#endif