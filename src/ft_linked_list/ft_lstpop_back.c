#include "libft.h"

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	head = *lst;
	if (!head)
		return (NULL);
	while (head->next && head->next->next)
		head = head->next;
	if (!head->next)
		return ((*lst = NULL), head);
	tmp = head->next;
	head->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}