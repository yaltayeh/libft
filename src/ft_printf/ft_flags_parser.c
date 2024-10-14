/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:52:52 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 19:53:42 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flags_parser(const char **fmt, size_t *numbers, t_flags flags)
{
	char			flags_character[16];
	char			*flag;

	ft_strlcpy(flags_character, FLAGS_CHARACTERS, sizeof(flags_character));
	flag = ft_strchr(flags_character, **fmt);
	while (flag)
	{
		if (ft_isdigit(*flag) && *flag != '0')
		{
			numbers[0] = ft_atoi_track(fmt);
			flags |= NUMBER;
		}
		else
		{
			*fmt = *fmt + 1;
			if (*flag == '0' || *flag == '-')
				numbers[0] = ft_atoi_track(fmt);
			else if (*flag == '.')
				numbers[1] = ft_atoi_track(fmt);
			flags |= (1 << (flag - flags_character));
		}
		flag = ft_strchr(flags_character, **fmt);
	}
	return (flags);
}
