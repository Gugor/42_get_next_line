/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:06:54 by hmontoya          #+#    #+#             */
/*   Updated: 2023/09/05 17:34:02 by hmontoya         ###   ########.fr       */
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

char    *ft_strchr(char *s, int c)
{
    int             i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (s + i);
        i++;
    }
    if (c == '\0')
        return (s + i);
    return (NULL);
}

char *ft_strcut(char const *s, ssize_t size)
{
	char *dup;
	ssize_t i;

	i = 0;
	dup = malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i <= size )
	{
		dup[i] = (char)s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_bufjoin(char **b1, char *b2)
{
	char *bb1;
	char *newstr;
	ssize_t i;
	ssize_t j;

	if (!*b1 && !b2)
        return (NULL);

	bb1 = *b1;
	i = -1;
	j = -1;
	newstr = (char *)malloc((ft_strlen(*b1) + ft_strlen(b2) + 1) * sizeof(char));
	if(!newstr)
		return (memfree(b1));
	while (bb1[++i])
		*(newstr + i) = bb1[i];	
	while (b2[++j])
		*(newstr + i + j) = b2[j];
	*(newstr + i + j) = '\0';
	return (newstr);
}
