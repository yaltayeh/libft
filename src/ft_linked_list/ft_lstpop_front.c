#include "libft.h"

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*item;

	item = *lst;
	if (!item)
		return (NULL);
	*lst = item->next;
	if(*lst)
		(*lst)->prev = NULL;
	item->next = NULL;
	return (item);
}