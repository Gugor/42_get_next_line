/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:06:54 by hmontoya          #+#    #+#             */
/*   Updated: 2023/08/22 17:41:48 by hmontoya         ###   ########.fr       */
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

char *ft_strcut(char const s, ssize_t size)
{
	char *dup;
	ssize_t i;

	dup = malloc((size + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	while (s[i] && i < size )
	{
		dup[i] = (char)s[i];
		i++;
	}
	dup[i] = '\n';
	return (dup);
}

char *ft_strjoin(char const *b1, char const *b2)
{
	char *newstr;
	ssize_t	b1_len;
	ssize_t	b2_len;
	ssize_t i;
	ssize_t j;

	if (!b2)
		return (b1);
	b1_len = ft_strlen(b1);	
	b2_len = ft_strlen(b2)
	i = 0;
	newstr = malloc((b1_len + b2_len) * sizeof(char *));
	while (b1[i])
		*(newstr + i) = b1[i++];	
	while (b2[j])
		*(newstr + i + j) = b2[j++];
	newstr[i + j] = '\0';
	return (newstr);
}
