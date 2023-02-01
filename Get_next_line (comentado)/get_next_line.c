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
	char	*buffer;
	char	*buffer_aux;
	char	*buffer_join;
	int		i;
	int		j;

	if (fd == -1)
		return (NULL);
	i = 0;
	j = 0;
	buffer = malloc(sizeof (char) * BUFFER_SIZE + 1);//sin proteger
	read(fd, buffer, BUFFER_SIZE);


	while (ft_strchr(buffer, 10) == NULL)
	{
		buffer_aux = ft_malloc(i);
		read(fd, buffer_aux, BUFFER_SIZE);
		buffer_join = ft_strjoin(buffer, buffer_aux);
		free(buffer);
		free(buffer_aux);
		buffer = ft_strjoin(buffer_join, "");
		free(buffer_join);
		i++;
	}


	// if (ft_strchr(buffer, 10) != NULL)
	// {
	// 	buffer_aux = ft_strchr(buffer, 10);
	// 	j = ft_strlen(buffer) - ft_strlen(buffer_aux);
	// 	//free(buffer_aux);
	// 	i = 0;
	// 	buffer_join = malloc(sizeof(char) * j + 1);//sin proteger
	// 	while (i < j)
	// 	{
	// 		buffer_join[i] = buffer[i];
	// 		i++;
	// 	}
	// 	buffer_join[i] = '\0';
	// 	free(buffer);
	// 	buffer = ft_strjoin(buffer_join, "");
	// }
	printf("%s", buffer);
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