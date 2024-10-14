/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:38:24 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/08/29 12:08:52 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(t_content))
{
	t_list	*p;
	t_list	*next_lst;

	if (lst == NULL)
		return ;
	p = *lst;
	while (p)
	{
		next_lst = p->next;
		ft_lstdelone(p, del);
		p = next_lst;
	}
	*lst = NULL;
}
