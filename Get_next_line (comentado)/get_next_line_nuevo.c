/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:36 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/01 15:49:21 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*buffer;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer = ft_read(static_buffer, fd);
	while (static_buffer != NULL)
	{
		if (ft_strchr(static_buffer, 10) != 0)
		{
			buffer = ft_memcpy(static_buffer);
			static_buffer = ft_chop_static_buffer(buffer);
			return (ft_return_line(buffer));
		}
		if (ft_strchr(static_buffer, 10) == 0)
		{
			buffer = ft_malloc(BUFFER_SIZE + 1);
			if (read(fd, buffer, BUFFER_SIZE) == 0)
			{
				free (buffer);
				buffer = ft_memcpy(static_buffer);
				static_buffer = NULL;
				return (buffer);
			}
			static_buffer = ft_strjoin(static_buffer, buffer);
		}
	}
	return (NULL);
}

char	*ft_read(char *buffer, int fd)
{
	long int	bytes_read;

	if (buffer == NULL)
	{
		buffer = ft_malloc(BUFFER_SIZE + 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((bytes_read) == 0)
			return (NULL);
	}
	else if (buffer != NULL)
		return (buffer);
	return (buffer);
}

char	*ft_chop_static_buffer(char *buffer)
{
	char	*return_buffer;
	int		i;
	int		j;

	return_buffer = ft_malloc(ft_strlen(buffer) - ft_strchr(buffer, 10) + 1);
	i = 0;
	j = ft_strchr(buffer, 10);
	while (buffer[j] != '\0')
	{
		return_buffer[i] = buffer[j];
		i++;
		j++;
	}
	return (return_buffer);
}

char	*ft_return_line(char *buffer)
{
	char	*return_buffer;
	int		n;
	int		i;

	return_buffer = ft_malloc(ft_strchr(buffer, 10) + 1);
	n = ft_strchr(buffer, 10);
	i = 0;
	while (i < n)
	{
		return_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (return_buffer);
}
