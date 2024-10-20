#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, t_content content)
{
	while (lst)
	{
		if (!ft_memcmp(&lst->content, &content, sizeof(t_content)))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}