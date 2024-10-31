/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:43:34 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/08/27 08:30:59 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstmap(t_node *lst, t_content (*f)(t_content), void (*del)(t_content))
{
	t_node	*newlst;
	t_node	*ptr;
	t_content new_content;

	if (!f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		ptr = ft_newnode(new_content);
		if (!ptr)
		{
			if (new_content.ptr != NULL)
				del(new_content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstpush_back(&newlst, ptr);
		lst = lst->next;
	}
	return (newlst);
}
