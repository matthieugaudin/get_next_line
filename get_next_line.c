/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:39 by mgaudin           #+#    #+#             */
/*   Updated: 2024/10/22 14:20:33 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

// int main(void)
// {
// 	int		fd;
// 	size_t	read_bytes;
// 	char	buffer[30];

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	read_bytes = read(fd, buffer, 5);
// }

char	*get_next_line(int fd)
{
	size_t	read_bytes;
	char	buffer[1024];

	if (fd < 0)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		
	}
	
	
}
