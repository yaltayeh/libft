#include "libft.h"

t_node	*ft_lstpop_front(t_node **lst)
{
	t_node	*head;
	t_node	*item;

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