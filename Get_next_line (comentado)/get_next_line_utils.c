/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:36 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/01 15:49:21 by imoro-sa         ###   ########.fr       */
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

char	*ft_strchr(char *buffer, int c)
{
	char	*str;
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == (char)c)
		{
			str = ft_strjoin((char *)&buffer[i], "");
			return (str);
		}
		i++;
	}
	if (buffer[i] == (char)c)
	{
		str = ft_strjoin((char *)&buffer[i], "");
		return (str);
	}
	return (NULL);
}

char	*ft_malloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc (size * nmemb);
	if (str == NULL)
		return (NULL);
	while (i < (size * nmemb))
	{
		str[i] = '\0';
		++i;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return ((char *)str);
	free(s1);
	free(s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	*str;
	int	n;

	str = (int *)s;
	n = ft_strlen(s);
	write (fd, str, n);
}
