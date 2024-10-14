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

typedef struct s_list
{
	t_content		content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	*ft_lstnew(t_content content);
size_t		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

void	ft_lstdelone(t_list *item, void (*del)(t_content));
void	ft_lstclear(t_list **lst, void (*del)(t_content));

void	ft_lstinsert(t_list **lst, t_list *new);
void	ft_lstpush_front(t_list **lst, t_list *new);
void	ft_lstpush_back(t_list **lst, t_list *new);

t_list	*ft_lstpop_front(t_list **lst);
t_list	*ft_lstpop_back(t_list **lst);

void	ft_lstiter(t_list *lst, void (*f)(t_content));
t_list	*ft_lstmap(t_list *lst, t_content (*f)(t_content), void (*del)(t_content));

#endif