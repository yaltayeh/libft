#include "libft.h"

t_node	*ft_lstpop_back(t_node **lst)
{
	t_node	*head;
	t_node	*tmp;

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