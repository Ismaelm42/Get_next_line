/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:48:19 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/01/23 13:27:03 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*buffer2;
	int		i;

	i = 0;
	if (fd == -1)
		return (NULL);
	buffer = malloc (sizeof (char) * BUFFER_SIZE + 1);
	read (fd, buffer, BUFFER_SIZE);
	while (ft_strchr(buffer, 10) == NULL)
	{
		buffer2 = malloc(ft_strlen(buffer) + 1);
		strcpy(buffer2, buffer);
		ft_free(buffer);
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + (i * BUFFER_SIZE)) + 1);
		strcpy(buffer, buffer2);
		read (fd, buffer, BUFFER_SIZE);
		ft_free(buffer2);
		i++;
	}
	return (NULL);
}




















//Dudas:
//BUFFER_SIZE para la correcta compilación
//fd = open (en el ejericio no piden ningun archivo de prueba.
//Debe poder abrir cualquier archivo)
//¿va en el main o está en la función?
//close debe ir al final del todo de la función principal sino se resetea "read"

