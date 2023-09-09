/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:36:58 by hmontoya          #+#    #+#             */
/*   Updated: 2023/09/09 15:40:45 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*memfree(char **s);
char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer);
char	*get_nline(char **buf);
//Utils
ssize_t	ft_strlen(char *s);
void	*ft_calloc(ssize_t count, ssize_t size);
char	*ft_bufjoin(char *b1, char *b2);
char	*ft_strcut(char *s, ssize_t size);
char	*ft_strchr(char *s, int c);
#endif
