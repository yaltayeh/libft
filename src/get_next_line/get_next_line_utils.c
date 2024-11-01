/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:35:16 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 00:46:40 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_strjoin_gnl_help(char **new_line_p, char *buffer, \
									size_t i1, size_t i2)
{
	char	*new_line;
	size_t	len;
	char	*left;

	left = buffer + i2;
	len = i1 + i2;
	new_line = malloc(len + 1);
	if (!new_line)
	{
		if (*new_line_p)
			free(*new_line_p);
		*new_line_p = NULL;
		return ;
	}
	new_line[len] = '\0';
	while (i2--)
		new_line[--len] = buffer[i2];
	while (i1--)
		new_line[--len] = (*new_line_p)[i1];
	if (*new_line_p)
		free(*new_line_p);
	*new_line_p = new_line;
	ft_strlcpy(buffer, left, BUFFER_SIZE + 1);
}

int	ft_strjoin_gnl(char **new_line, char *buffer)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (*new_line)
		i1 = ft_strlen(*new_line);
	while (buffer[i2] != '\n' && buffer[i2] != '\0')
		i2++;
	i2 += !!buffer[i2];
	ft_strjoin_gnl_help(new_line, buffer, i1, i2);
	if (!*new_line)
		return (0);
	i1 = 0;
	while ((*new_line)[i1] != '\0')
	{
		if ((*new_line)[i1] == '\n')
			return (1);
		i1++;
	}
	return (0);
}
