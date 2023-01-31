/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:48:19 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/01/23 13:27:03 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *buffer, int c)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == (char)c)
			return ((char *)&buffer[i]);
		i++;
	}
	if (buffer[i] == (char)c)
		return ((char *)&buffer[i]);
	return (NULL);
}

void	ft_free(char *buffer)
{
	long int	i;

	i = 0;
	while (*buffer)
	{
		buffer[i] = '\0';
		i++;
	}
	free(buffer);
}

char	*ft_malloc(int n)
{	
	char	*buffer;

	buffer = malloc(sizeof (char) * (BUFFER_SIZE + (n * BUFFER_SIZE)) + 1);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

char	*ft_buffcpy(char *buffer_dst, char *buffer_src)
{
	long int	i;

	i = 0;
	while (buffer_src[i] != '\0')
	{
		buffer_dst[i] = buffer_src[i];
		i++;
	}
	return (&buffer_dst[i]);
}

//hacerlo con tres whiles, creo que debería resolver los problemas
//necesito funciones tanto para la reserva de memoria como para liberarla
//MUY IMPORTANTE

//While read =! 0

//while strchr == 10

//while strchr != 10






























	// char	*buffer;
	// char	*buffer2;
	// int		count;

	// count = 0;
	// buffer = malloc (sizeof (char) * BUFFER_SIZE + 1);
	// read (fd, buffer, BUFFER_SIZE);
	// printf ("%s", buffer);

	// while (strchr (buffer, 10) == NULL)
	// {
	// 	buffer2 = malloc(ft_strlen(buffer) + 1);
	// 	strcpy(buffer2, buffer);
	// 	ft_free(buffer);
	// 	buffer = malloc(sizeof (char) * (BUFFER_SIZE + (count * BUFFER_SIZE)) + 1);
	// 	strcpy(buffer, buffer2);
	// 	read (fd, buffer, BUFFER_SIZE);
	// 	printf ("%s", buffer);
	// 	ft_free(buffer2);
	// 	count ++;
	// }
	// while (strchr (buffer, 10) != NULL)
	// {
	// 	count = ft_strlen(strchr(buffer, 10));
	// 	buffer = 
	// }

	// printf("\n");
	// return (buffer);


