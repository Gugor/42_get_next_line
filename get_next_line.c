/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:00:21 by hmontoya          #+#    #+#             */
/*   Updated: 2023/08/29 19:16:41 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void memfree(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
} 

char *read_line(int fd, char **buffer)
{
	char	*chunk;
	char	*tmp;
	ssize_t	*byte_read;
	int		i;
	chunk = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!chunk)
	{
		memfree(&buffer);
		return (NULL);
	}
	tmp = NULL;
	byte_read = 1;
	i = 0;
	while ((byte_read = read(fd, chunk, BUFFER_SIZE)) > 0)
	{
		while (tmp[i] != '\n)
			i++;
		tmp = ft_bufjoin(&buffer, chunk);
		if (!tmp)
		{
			memfree(&chunk);
			return (NULL);
		} 
	}	
	memfree(&chunk);
	return (tmp);

char *get_nline(char **buf)
{
	ssize_t	line_size;
	char	*line;
	ssize_t	buf_len;

	line_size = 0;
	line = NULL;
	buf_len = ft_strlen(*buf);
	while (line_size < buf_len  && (*buf)[line_size] != '\n')
				line_size++;
	if ((*buf)[line_size] == '\n')
	{
		line = ft_strcut(*buf,line_size);
		*buf += line_size + 1;
		return (line);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char	*line;
	ssize_t bytes;

	if (fd < 0)
		return (NULL);
	line = NULL;
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (NULL);
	}
	buffer = read_line(fd, &buffer);
	line = get_nline(&buffer);
	return (line);
}
