

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *buffer;
	char	*chunk;
	ssize_t byte;
	ssize_t i;
	char *line;

	chunk = malloc(BUFFER_SIZE * sizeof(char *));
	byte = read(fd, chunk, BUFFER_SIZE);
	i = 0;
	printf(":: Number of bytes allocated %zu\n", byte);
	while (bytes > 0 && buffer[i] != '\n')
	{
		printf(">> Buffer (%zu bytes)\n\n", i);
		if (i = ft_strchar(buffer,'\n'))
		{
			
		}
		i++;	
		printf("%c\n", buffer[i]);
	}
     return (buffer);
}
