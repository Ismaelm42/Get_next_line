/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:44 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/10 17:12:55 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*static_buffer;
	long int	bytes_read;

	bytes_read = 1;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes_read > 0)
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
			if (buffer != NULL)
			{
				printf("BUFFER1:%s\n", buffer);
				printf("STATIC1:%s\n", static_buffer);
				static_buffer = NULL;
				return (buffer);
			}
			else if (static_buffer == NULL)
			{
				printf("BUFFER2:%s\n", buffer);
				printf("STATIC2:%s\n", static_buffer);
				return (static_buffer);
			}
		}
		if (ft_strchr(buffer, 10) == 0)
			static_buffer = buffer;
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
