/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:06:54 by hmontoya          #+#    #+#             */
/*   Updated: 2023/08/23 18:36:00 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t ft_strlen(char *s)
{
	ssize_t i;

	i = 0;
	while (s[i])
		i++;	
	return (i);
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

char *ft_bufjoin(char const *b1, char const *b2)
{
	char *newstr;
	ssize_t	b1_len;
	ssize_t	b2_len;
	ssize_t i;
	ssize_t j;

	if (!b2)
		return ((char *)b1);
	b1_len = ft_strlen((char *)b1);	
	b2_len = ft_strlen((char *)b2);
	i = -1;
	j = -1;
	newstr = malloc((b1_len + b2_len + 1) * sizeof(char));
	if(!newstr)
		return (NULL);
	while (++i < b1_len)
		*(newstr + i) = (char)b1[i];	
	while (++j < b2_len)
		*(newstr + i + j) = (char)b2[j];
	*(newstr + i + j) = '\0';
	return (newstr);
}
