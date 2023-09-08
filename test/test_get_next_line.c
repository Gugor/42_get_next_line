/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:00:39 by hmontoya          #+#    #+#             */
/*   Updated: 2023/09/08 16:58:25 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdlib.h>

int main (int argc, char **argv)
{
	char *filename;
	char *line;
	int fd;
	int i;
	int EOF1;

	fd = 0;
	filename = argv[1];
	line = NULL;
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
	EOF1 = 0;
	i = 0;
	while (EOF1 < 1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			EOF1 = 1;
			printf(">> NULL Line %i: %s\n", i++, line);
			break;
		}
		printf(">> Main Line %i: %s\n\n", i++, line);
		memfree(&line);
	}
	close(fd);
	system("leaks get_next_line.out");
	return (0);
}
