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
	char	buffer[12];

	printf("%ld\n", read(fd, buffer, 11));
	ft_putstr_fd(buffer, 1);
	return (NULL);
}

/*ideas:
Realizar un while para que el read vaya leyendo de uno en uno hasta encontrar un salto de línea.
Retornar entonces el entero y con el cargar un buff con malloc mismo para cargar la línea.
Seguir hacia delante y repetir el proceso hasta encontrar el caracter '\0'
*/
