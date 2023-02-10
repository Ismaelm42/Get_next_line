/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:06:28 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/10 17:06:34 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open ("TXT.md", O_RDONLY);
	while (i < 20)
	{
		printf("%s", get_next_line(fd));
		//get_next_line(fd);
		i++;
	}
	return (0);
}
