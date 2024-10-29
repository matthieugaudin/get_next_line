/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:39 by mgaudin           #+#    #+#             */
/*   Updated: 2024/10/29 17:29:40 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_fill_line() {}

void	ft_clean_stash() {}

/* 
	Fills the stash with the entire file text at the first call of get_next_line
	Doesn't do anything to the stash after the first call
*/

void	ft_fill_stash(char **pstash, int fd) 
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE] = '\0';
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	printf("%d", read_bytes);
	while (read_bytes > 0)
	{
		printf("%d", read_bytes);
		*pstash = ft_strjoin(*pstash, buffer);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char *stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	stash = "";

	ft_fill_stash(&stash, fd);
	return (NULL);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
}