/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:36:34 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/08/27 07:38:11 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *item, void (*del)(t_content))
{
	if (item && del)
	{
		if (item->prev)
			item->prev->next = NULL;
		if (item->next)
			item->next->prev = NULL;

		ft_lstpush_back(&item->prev, item->next);
		del(item->content);
		free(item);
	}
}
