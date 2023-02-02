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
	char		*buffer_join;
	static char	*rest_of_buffer;
	size_t		n1;
	size_t		n2;

	if (fd == -1)
		return (NULL);
	n1 = 1;
	n2 = 0;
	buffer = ft_malloc(sizeof(char), BUFFER_SIZE + 1);
	read(fd, buffer, BUFFER_SIZE);
	if (rest_of_buffer != NULL)
	{
		buffer = ft_strjoin(rest_of_buffer, buffer);
		rest_of_buffer--;
		free(rest_of_buffer);
	}
	while (ft_strchr(buffer, 10) == NULL)
	{
		buffer_join = ft_malloc(sizeof(char), (BUFFER_SIZE * n1) + 1);
		read(fd, buffer_join, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, buffer_join);
		n1++;
	}
	if (ft_strchr(buffer, 10) != NULL)
	{
		rest_of_buffer = ft_strchr(buffer, 10);
		rest_of_buffer++;
		n2 = ft_strlen(buffer) - ft_strlen(rest_of_buffer);
		buffer_join = ft_malloc(sizeof(char), n2 + 1);
		n1 = 0;
		while (n1 < n2)
		{
			buffer_join[n1] = buffer[n1];
			n1++;
		}
		buffer_join[n1] = '\0';
		free(buffer);
		ft_putstr_fd(buffer_join, 1);
		free(buffer_join);
	}
	return (NULL);
}

// char	*get_next_line(int fd)
// {
// 	char	*buffer;
// 	char	*buffer_aux;
// 	char	*buffer_join;
// 	int		i;

// 	if (fd == -1)
// 		return (NULL);
// 	i = 0;
// 	buffer = malloc(sizeof (char) * BUFFER_SIZE + 1);
// 	read(fd, buffer, BUFFER_SIZE);
// 	while (ft_strchr(buffer, 10) == NULL)
// 	{
// 		buffer_aux = ft_malloc(i);
// 		read(fd, buffer_aux, BUFFER_SIZE);
// 		buffer_join = ft_strjoin(buffer, buffer_aux);
// 		free(buffer);
// 		free(buffer_aux);
// 		buffer = buffer_join;
// 	}
// 	printf("%s", buffer);
// 	return (NULL);
// }

//Dudas:
//BUFFER_SIZE para la correcta compilación
//fd = open (en el ejericio no piden ningun archivo de prueba.
//Debe poder abrir cualquier archivo)
//¿va en el main o está en la función?
//close debe ir al final del todo de la función principal sino se resetea "read"





//if (ft_strchr(buffer, 10) != NULL)
//esto se imrpime
//debe retornar lo sobrante
//guardar las variables con un malloc (igual ft_calloc no merece tanto la pena)
//es posible que el salto de línea haya que saltarselo ya a cada llamada de la función.
