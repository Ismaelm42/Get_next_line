/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:48 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/01 15:55:04 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_return_line(char *buffer, char *static_buffer);
char	*ft_line_feed_check(int fd, char *buffer);
char	*ft_static_buffer_check(char *buffer, char *static_buffer);
char	*ft_prueba(char *buffer, char *static_buffer);


//int		main(void);

int		ft_strlen(const char *s);
char	*ft_strchr(char *buffer, int c);
char	*ft_malloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);

#endif
