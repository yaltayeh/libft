#include "libft.h"

void	ft_lstinsert(t_node **lst, t_node *new)
{
	t_node	*tmp;

	tmp = NULL;
	if (*lst)
	{
		tmp = (*lst)->next;
		if (tmp)
			tmp->prev = NULL;
		(*lst)->next = NULL;
	}
	ft_lstpush_back(lst, new);
	ft_lstpush_back(lst, tmp);
}