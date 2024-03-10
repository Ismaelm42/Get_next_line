#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd);
char	*get_buffer(long int *bytes_read, int fd);
char	*read_fd_loop(int fd, char *static_buff);
char	*get_line(char *static_buff);
char	*get_static(char *static_buff);

#endif
