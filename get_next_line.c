/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:00:21 by hmontoya          #+#    #+#             */
/*   Updated: 2023/08/23 18:30:03 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void memfree(char *s)
{
	if(s)
		free(s);
} 

char *read_line(int fd, char **buf, char *line)
{
	char	*chunk;
	ssize_t bytes;
	ssize_t line_size;

	bytes = 0;
	line_size = 0;
	chunk = malloc(BUFFER_SIZE * sizeof(char));
	if (!chunk)
		return (NULL);
	while ((*buf)[line_size] && (*buf)[line_size] != '\n')
			line_size++;
	if ((*buf)[line_size] == '\n')
	{
		line = ft_strcut(*buf,line_size);
		*buf += line_size + 1;
		return (line);
	}
	else
	{
		bytes = read(fd, chunk, BUFFER_SIZE);
		if (bytes > 0)
			*buf = ft_bufjoin(*buf, chunk);
		memfree(chunk);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char	*chunk;
	char	*line;
	ssize_t bytes;

	if(fd != 3)
		return (NULL);
	chunk = malloc(BUFFER_SIZE * sizeof(char));
	line = NULL;
	bytes = read(fd, chunk, BUFFER_SIZE);
	if (!buffer)
		buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (bytes > 0)
	{
		buffer = ft_bufjoin(buffer, chunk);
		memfree(chunk);
	}
	else
	{
		memfree(buffer);
		return (NULL);
	}
	while (!line && bytes > 0)
		read_line(fd, &buffer, line);
	return (line);
}
