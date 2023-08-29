
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 42
#endif

void memfree(char **s);
char	*get_next_line(int fd);
char	*get_nline(char **buf);
//Utils
ssize_t	ft_strlen(char *s);
char	*ft_bufjoin(char **b1, char *b2);
char	*ft_strcut(char const *s, ssize_t size);

