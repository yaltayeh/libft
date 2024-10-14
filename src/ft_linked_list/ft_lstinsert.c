#include "libft.h"

void	ft_lstinsert(t_list **lst, t_list *new)
{
	t_list	*tmp;

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