/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_ref_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:43:04 by hmontoya          #+#    #+#             */
/*   Updated: 2023/08/22 18:27:44 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void print_buff(char const *b)
{
	int i;

	i = 0;
	printf("\n New Line: \n");
	while (b[i])
	{
		write(1,&b[i],1);
		i++;
	}
}

void move_buff_ref(char **buff, int size)
{
	print_buff(*buff);
	*buff += size;
}

int main(void)
{
	static char *buff = BUFFER_CONTENT;
	while (*buff)
	{
		move_buff_ref(&buff,LINE_SIZE);
	}
	return (0);
}
