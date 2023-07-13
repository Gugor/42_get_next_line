
#include "../get_next_line.h"

#include <stdlib.h>

int main (int argc, char **argv)
{
	char *filename;
	char *line;
	int fd;
	int i;

	fd = 0;
	filename = argv[1];
	printf(":: Filename: %s\n", filename);
	if (!filename)
	{
		printf(":: Error: missing filename argument. %s\n", filename);
		exit(1);
	}
	fd = open (filename, O_RDONLY);
	printf("=== Fd:%i ===\n",fd);
	if (fd == -1 )
	{
		printf(":: Error: the file could not be opened. (%s)", filename);
		exit(2);
	}
	while (fd > -1)
	{
		line = get_next_line(fd);
		if(!line)
			exit(3);
		printf(">> Line %i: %s\n\n", i++, line);
	}
	close(fd);
	return (0);
}
