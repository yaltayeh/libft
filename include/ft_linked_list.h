#ifndef FT_LINKED_LIST_H
# define FT_LINKED_LIST_H

#include <stdlib.h>

typedef union u_content
{
	void *ptr;
	long i64;
	int	i32;
	short	i16;
	char	i8;
	unsigned long	u64;
	unsigned int	u32;
	unsigned short	u16;
	unsigned char	u8;
}	t_content;

typedef struct s_node
{
	t_content		content;
	struct s_node	*next;
	struct s_node	*prev;
	void			*parent;
}	t_node;

t_node	*ft_newnode(t_content content);
size_t		ft_lstsize(t_node *lst);

t_node	*ft_lstlast(t_node *lst);

void	ft_lstdelone(t_node *item, void (*del)(t_content));
void	ft_lstclear(t_node **lst, void (*del)(t_content));

void	ft_lstinsert(t_node **lst, t_node *new);
void	ft_lstpush_front(t_node **lst, t_node *new);
void	ft_lstpush_back(t_node **lst, t_node *new);

t_node	*ft_lstpop_front(t_node **lst);
t_node	*ft_lstpop_back(t_node **lst);

void	ft_lstiter(t_node *lst, void (*f)(t_content));
t_node	*ft_lstmap(t_node *lst, t_content (*f)(t_content), void (*del)(t_content));

t_node	*ft_lstsearch(t_node *lst, t_content content);

#endif