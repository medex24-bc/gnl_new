#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <stdio.h>
#include <fcntl.h> // pour open()
#include <stdlib.h> // pour free() & malloc
#include <unistd.h> // pour read()

static char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_return_position(char *str, char c);
size_t  ft_strlcpy(char *dst, char *src, size_t size);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strdup(char *s);
char    *ft_strchr (char *s, int c);
size_t  ft_strlen (char *s);
void    *ft_memcpy(void *dst, void *src, size_t n);

#endif
