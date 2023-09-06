
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 42
#endif

char  *memfree(char **s);
char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer);
char	*get_nline(char **buf);
//Utils
ssize_t	ft_strlen(char *s);
char	*ft_bufjoin(char *b1, char *b2);
char	*ft_strcut(char const *s, ssize_t size);
char	*ft_strchr(char *s, int c);

