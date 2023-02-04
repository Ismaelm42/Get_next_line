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
	static char	*static_buffer;

	if (fd == -1)
		return (NULL);
	buffer = ft_malloc(sizeof(char), BUFFER_SIZE + 1);
	if (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		if (static_buffer != NULL)
			buffer = ft_static_buffer_check(buffer, static_buffer);
		while (ft_strchr(buffer, 10) == NULL)
			buffer = ft_line_feed_check(fd, buffer);
		if (ft_strchr(buffer, 10) != NULL)
		{
			static_buffer = ft_strchr(buffer, 10);
			static_buffer++;
			ft_return_line(buffer, static_buffer);
		}
	}
	return (NULL);
}

char	*ft_static_buffer_check(char *buffer, char *static_buffer)
{
	buffer = ft_strjoin(static_buffer, buffer);
	static_buffer--;
	free(static_buffer);
	return (buffer);
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

char	*ft_return_line(char *buffer, char *static_buffer)
{
	size_t	n;
	size_t	length;
	char	*return_buffer;

	length = ft_strlen(buffer) - ft_strlen(static_buffer);
	return_buffer = ft_malloc(sizeof(char), length + 1);
	n = 0;
	while (n < length)
	{
		return_buffer[n] = buffer[n];
		n++;
	}
	return_buffer[n] = '\0';
	free(buffer);
	ft_putstr_fd(return_buffer, 1);
	return (NULL);
	free(return_buffer);
}
//free no se va a realizar aquí. Echar un vistazo a ver si se puede arreglar
