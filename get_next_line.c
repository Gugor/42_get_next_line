

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[1000];
	ssize_t byte;

	byte = read(fd, buffer, 1000);
	//buffer = (char *)malloc(byte * sizeof(char *));
	/*if (!buffer)
	{
		printf(":: Error: memory allocation failed. (0 bytes from %zu)\n",byte);
		return (NULL);
	}*/
	printf(":: Number of bytes allocated %zu\n", byte);
	while (byte > 0)
	{
		printf(">> Buffer (%zu bytes)\n\n", byte);
		byte += read(fd, buffer, 1000 * byte);
		printf("%c\n", buffer[byte]);
		return (buffer);
	}
     return (buffer);
}
