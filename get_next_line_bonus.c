/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:00:21 by hmontoya          #+#    #+#             */
/*   Updated: 2023/09/09 19:28:00 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*memfree(char **s)
{
	if (s && *s)
		free(*s);
	*s = NULL;
	return (NULL);
}

char	*read_line(int fd, char *buffer)
{
	char	*chunk;
	ssize_t	bytes_read;

	bytes_read = 1;
	chunk = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!chunk)
		return (memfree(&buffer));
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

char	*get_nline(char **buf)
{
	ssize_t	ln_size;
	char	*tmp;
	char	*line;

	ln_size = 0;
	tmp = NULL;
	while ((*buf)[ln_size] && (*buf)[ln_size] != '\n')
		ln_size++;
	if ((*buf)[ln_size] == '\n')
		ln_size++;
	line = ft_strcut(*buf, ln_size);
	if (!line)
		return (memfree(buf));
	if ((*buf)[ln_size] != '\0')
	{
		tmp = ft_strcut(*buf + ln_size, ft_strlen(*buf) - (ln_size));
		if (!tmp && !memfree(&line))
			return (memfree(buf));
	}
	memfree(buf);
	*buf = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (memfree(&buffer[fd]));
	line = NULL;
	if (!buffer[fd])
	{
		buffer[fd] = (char *)ft_calloc(1, sizeof(char));
		if (!buffer[fd])
			return (memfree(buffer));
	}
	if (!ft_strchr(buffer[fd], '\n'))
		buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd] || !buffer[fd][0])
		return (memfree(buffer));
	line = get_nline(&buffer[fd]);
	if (!line)
		return (memfree(buffer));
	return (line);
}
