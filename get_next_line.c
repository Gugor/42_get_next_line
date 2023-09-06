/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:00:21 by hmontoya          #+#    #+#             */
/*   Updated: 2023/09/06 20:43:32 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char  *memfree(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
} 

char *read_line(int fd, char *buffer)
{
	char		*chunk;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (!buffer)
		buffer = (char *)malloc(1);
	if (!buffer)
		return (NULL);
	chunk = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!chunk)
		return (NULL);
	chunk[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(chunk, '\n'))
	{
		bytes_read = read(fd, chunk, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			chunk[bytes_read] = '\0';
			buffer = ft_bufjoin(buffer, chunk);
			if (!buffer)
				return (memfree(&chunk));
		}
	}
	memfree(&chunk);
	if (!buffer[0])
		return (NULL);
	if (bytes_read < 0) 
		return (memfree(&buffer));
	return (buffer);
}
char *get_nline(char **buf)
{
	ssize_t	line_size;
	char	*tmp;
	char	*line;

	line_size = 0;
	line = NULL;
	tmp = NULL;
	if (!*buf)
		return (NULL);
	while ((*buf)[line_size] && (*buf)[line_size] != '\n')
				line_size++;
	if ((*buf)[line_size] == '\n' || (*buf)[line_size] == '\0' )
	{
		line = ft_strcut(*buf,line_size);
		if (!line)
			return (memfree(&line));
		tmp = ft_strcut(*buf + line_size + 1, ft_strlen(*buf) - (line_size + 1));
		if (!tmp)
			return (memfree(&tmp));
		memfree(buf);
		*buf = tmp;
		return (line);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if (!buffer || (buffer && !ft_strchr(buffer, '\n'))) 
		buffer = read_line(fd, buffer);
	if (!buffer)
		return (memfree(&buffer));
	line = get_nline(&buffer);
	if (!line)
		return (memfree(&buffer));
	return (line);
}
