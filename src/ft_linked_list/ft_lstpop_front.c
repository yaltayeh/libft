#include "libft.h"

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*head;
	t_list	*item;

	head = *lst;
	if (!head)
		return (NULL);
	item = head;
	head = item->next;
	if(head)
		head->prev = NULL;
	item->next = NULL;
	*lst = head;
	return (item);
}