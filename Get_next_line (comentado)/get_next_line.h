/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:48 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/13 15:40:14 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

char		*get_next_line(int fd);
char		*ft_chop_static_buffer(char *buffer);
char		*ft_return_line(char *buffer);
char		*ft_return_no_feed_line(char *buffer);

int			ft_strlen(char *s);
int			ft_strchr(char *s, int c);
char		*ft_malloc(size_t nmemb);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_memcpy(char *src);

#endif