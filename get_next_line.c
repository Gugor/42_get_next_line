/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:00:21 by hmontoya          #+#    #+#             */
/*   Updated: 2023/09/08 20:29:58 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char  *memfree(char **s)
{
	if (s && *s)
		free(*s);
	*s = NULL;
	return (NULL);
} 

char *read_line(int fd, char *buffer)
{
	char		*chunk;
	ssize_t		bytes_read;

	bytes_read = 1;
	chunk = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!chunk)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(chunk, '\n'))
	{
		bytes_read = read(fd, chunk, BUFFER_SIZE);
		if (bytes_read < 0 && !memfree(&buffer)) 
			return (memfree(&chunk));
		if (bytes_read > 0)
		{
			chunk[bytes_read] = '\0';
			buffer = ft_bufjoin(buffer, chunk);
			if (!buffer)
				return (memfree(&chunk));
		}
	}
	memfree(&chunk);
	if (!(*buffer))
		return (memfree(&buffer));
	return (buffer);
}

char *get_nline(char **buf)
{
	ssize_t	ln_size;
	char	*tmp;
	char	*line;

	ln_size = 0;
	line = NULL;
	tmp = NULL;
	if (!buf || !(*buf))
		return (memfree(buf));
	while ((*buf)[ln_size] && (*buf)[ln_size] != '\n')
				ln_size++;
	if ((*buf)[ln_size] == '\n' || (*buf)[ln_size] == '\0')
	{
		line = ft_strcut(*buf,ln_size + 1);
		if (!line)
			return (memfree(buf));
		tmp = ft_strcut(*buf + ln_size + 1, ft_strlen(*buf) - (ln_size));
		if (!tmp)
			return (memfree(buf));
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
	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!ft_strchr(buffer, '\n')) 
		buffer = read_line(fd, buffer);
	if (!buffer)
		return (memfree(&buffer));
	line = get_nline(&buffer);
	if (!line)
		return (memfree(&buffer));
	return (line);
}
