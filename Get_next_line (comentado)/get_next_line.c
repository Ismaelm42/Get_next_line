/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:44 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/01 15:55:55 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*buffer2;
	static char	*static_buffer;

	if (fd == -1)
		return (NULL);
	buffer = ft_malloc(sizeof(char), BUFFER_SIZE + 1);
	if (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		if (static_buffer != NULL)
		{
			buffer = ft_strjoin(static_buffer, buffer);
			free(static_buffer--);
		}
		while (ft_strchr(buffer, 10) == NULL)
			buffer = ft_line_feed_check(fd, buffer);
		if (ft_strchr(buffer, 10) != NULL)
		{
			static_buffer = ft_strchr(buffer, 10);
			static_buffer++;
			return (ft_return_line(buffer, static_buffer));
		}
	}
	else if (read(fd, buffer, BUFFER_SIZE) == 0)
	{
		if (static_buffer == NULL)
			return (NULL);
		else if (ft_strchr(static_buffer, 10) == NULL)
		{
			buffer = NULL;
			return (static_buffer);
		}
		else if (ft_strchr(static_buffer, 10) != NULL)
		{
			buffer = ft_strchr(static_buffer, 10);
			buffer++;
			buffer2 = ft_return_line(static_buffer, buffer);
			static_buffer = buffer;
			return (buffer2);
		}
	}
	return (NULL);
}

char	*ft_line_feed_check(int fd, char *buffer)
{
	char	*storage_buffer;
	int		n;

	n = 1;
	storage_buffer = ft_malloc(sizeof(char), (BUFFER_SIZE * n) + 1);
	if (read(fd, storage_buffer, BUFFER_SIZE) != 0)
	{
		buffer = ft_strjoin(buffer, storage_buffer);
		n++;
	}
	return (buffer);
}

char	*ft_return_line(char *buffer1, char *buffer2)
{
	size_t	n;
	size_t	length;
	char	*return_buffer;

	length = ft_strlen(buffer1) - ft_strlen(buffer2);
	return_buffer = ft_malloc(sizeof(char), length + 1);
	n = 0;
	while (n < length)
	{
		return_buffer[n] = buffer1[n];
		n++;
	}
	//free(buffer1);
	//printf("print:%s", return_buffer);
	return (return_buffer);
	//free(return_buffer);
}
