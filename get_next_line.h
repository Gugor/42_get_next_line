
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char **buf, char *line);
//Utils
ssize_t	ft_strlen(char *s);
char	*ft_bufjoin(char const *b1, char const *b2);
char	*ft_strcut(char const *s, ssize_t size);

