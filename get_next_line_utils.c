/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:06:54 by hmontoya          #+#    #+#             */
/*   Updated: 2023/09/08 20:04:53 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

ssize_t ft_strlen(char *s)
{
	ssize_t i;

	i = 0;
	while (s[i])
		i++;	
	return (i);
}

void *ft_calloc(ssize_t count, ssize_t size)
{
    void    *ptr;
	ssize_t          i;
    unsigned char   *b;

    ptr = (void *)malloc(count * size);
    if (!ptr)
        return (0);
    i = 0;
    b = (unsigned char *)ptr;
    while (i < count * size)
    {
        b[i] = 0;
        i++;
    }
    ptr = (void *) b;
    return ((void *)ptr);
}

char    *ft_strchr(char *s, int c)
{
    int             i;

    i = 0;
	if (!s || !(*s))
		return (NULL);
    while (*(s + i))
    {
        if (*(s + i) == c)
            return (s + i);
        i++;
    }
    return (NULL);
}

char *ft_strcut(char *s, ssize_t size)
{
	char *dup;
	ssize_t i;

	i = 0;
	dup = ft_calloc((size + 1),  sizeof(char));
	if (!dup)
		return (NULL);
	while (i < size )
	{
		dup[i] = (char)s[i];
		i++;
	}
	return (dup);
}

char *ft_bufjoin(char *b1, char *b2)
{
	char *newstr;
	ssize_t i;
	ssize_t j;

	if ((!b1 && !b2))
        return (NULL);

	i = -1;
	j = -1;
	newstr = (char *)malloc((ft_strlen(b1) + ft_strlen(b2) + 1) * sizeof(char));
	if(!newstr)
		return (memfree(&b1));
	while (b1[++i])
		*(newstr + i) = b1[i];	
	while (b2[++j])
		*(newstr + i + j) = b2[j];
	newstr[i + j] = '\0';
	memfree(&b1);
	return (newstr);
}
