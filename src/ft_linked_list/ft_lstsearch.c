#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, t_content content)
{
	while (lst)
	{
		if (lst->content.i64 == content.i64)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}