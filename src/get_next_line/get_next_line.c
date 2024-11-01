/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:38:39 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 00:46:43 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*error_handling_gnl(char **new_line, char *buffer)
{
	buffer[0] = '\0';
	if (*new_line)
	{
		free(*new_line);
		*new_line = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*new_line;
	ssize_t		bytes_read;

	new_line = NULL;
	if (fd > FD_MAX || fd < 0)
		return (NULL);
	if (!buffer[fd][0])
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	else
		bytes_read = ft_strlen(buffer[fd]);
	while (bytes_read)
	{
		if (bytes_read == -1)
			return (error_handling_gnl(&new_line, buffer[fd]));
		buffer[fd][bytes_read] = '\0';
		if (ft_strjoin_gnl(&new_line, buffer[fd]))
			return (new_line);
		if (!new_line)
			return (error_handling_gnl(&new_line, buffer[fd]));
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (new_line);
}
