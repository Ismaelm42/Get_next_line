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
	char		*buffer;
	static char	*static_buffer;
	long int	bytes_read;

	bytes_read = 1;
	if (fd == -1)
		return (NULL);
	while (bytes_read > 0)
	{
		buffer = ft_malloc(BUFFER_SIZE + 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (static_buffer != NULL)
			buffer = ft_strjoin(static_buffer, buffer);
		if (ft_strchr(buffer, 10) != 0)
		{
			static_buffer = ft_chop_static_buffer(buffer);
			return (ft_return_line(buffer));
		}
		if (bytes_read == 0)
		{
			static_buffer = NULL;
			return (ft_return_no_feed_line(buffer));
		}
		if (ft_strchr(buffer, 10) == 0)
			static_buffer = ft_strjoin(buffer, "");
	}
	return (NULL);
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

char	*ft_return_no_feed_line(char *buffer)
{
	char	*return_buffer;
	int		n;
	int		i;

	return_buffer = ft_malloc(ft_strlen(buffer) + 1);
	n = ft_strlen(buffer);
	i = 0;
	if (n == 0)
	{
		free (return_buffer);
		return (NULL);
	}
	while (i < n)
	{
		return_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (return_buffer);
}
