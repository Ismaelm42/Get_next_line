/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:06:28 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/01 15:56:26 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i;

	fd = open ("TXT.md", O_RDONLY);
	i = 1;
	while (i <= 14)
	{
		printf("RETURN:%s", get_next_line(fd));
		//get_next_line(fd);
		i++;
	}
	return (0);
}
