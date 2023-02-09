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

	if (fd == -1)
		return (NULL);
	while (bytes_read > 0 || static_buffer != NULL)
	{
		buffer = ft_malloc(BUFFER_SIZE + 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (static_buffer != NULL)
		{
			buffer = ft_strjoin(static_buffer, buffer);
			free (static_buffer);
		}
		if (ft_strchr(buffer, 10) != 0)
		{
			static_buffer = ft_chop_static_buffer(buffer);
			return (ft_return_line(buffer));
		}
		if (bytes_read == 0)
		{
			static_buffer = NULL;
			return (buffer);
		}
		if (ft_strchr(buffer, 10) == 0)
		{
			static_buffer = buffer;
			bytes_read++;
		}
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

char	*ft_line_feed_check(int fd, char *buffer)
{
	char		*return_buffer;
	long int	nbr;

	while (ft_strchr(buffer, 10) != 0 || nbr != 0)
	{
		return_buffer = ft_malloc(BUFFER_SIZE);
		nbr = read(fd, return_buffer, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, return_buffer);
		free(return_buffer);
	}
	return (buffer);
}
