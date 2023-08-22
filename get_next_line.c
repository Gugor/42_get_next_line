/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:00:21 by hmontoya          #+#    #+#             */
/*   Updated: 2023/08/22 18:32:39 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_line(fd, char **buf)
{
	ssize_t line_size;
	int i;

	i = 0;
	while ( *buf[i] != '\n')
	{
		i++;	
	}
	while (buffer[line_size] && buffer[line_size] != '\n')
			line_size++;
	if (buffer[line_size] == '\n')
	{
		has_EOL = 1;
	}
	else
	{
			bytes = read(fd, chunk, BUFFER_SIZE);
			if (bytes > 0)
				buffer = ft_strjoin(buffer, chunk);
			has_EOL = 0;
		}
	return (NULL);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char	*chunk;
	char	*line;
	ssize_t byte;
	int has_EOL;

	chunk = malloc(BUFFER_SIZE * sizeof(char *));
	byte = read(fd, chunk, BUFFER_SIZE);
	if (bytes > 0)
		buffer = ft_strjoin(buffer, chunk);
	while (!has_EOL)
	{
	}
	printf(":: Number of bytes allocated %zu\n", byte);
	printf(":: BUFFER_SIZE  %d\n", BUFFER_SIZE);
	return (line);
}
