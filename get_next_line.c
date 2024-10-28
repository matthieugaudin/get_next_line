/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:39 by mgaudin           #+#    #+#             */
/*   Updated: 2024/10/28 18:36:36 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1 - loop and verify if \n
// 2 - if there is : return the line nor NULL
// 3 - if there is : delete all before \n

char	*ft_verify_stash(char **pstash)
{
	size_t	i;
	char	*line;

	i = 0;
	while (pstash[i])
	{
		line[i] = pstash[i];
		if (line[i] == '\n')
		{
			**pstash = ft_memchr(pstash, '\n', ft_strlen(pstash));
			return (line);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	size_t		read_bytes;
	char		buffer[1024];
	char		*line;
	static char *stash;

	if (fd < 0)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		if (!ft_strjoin(stash, buffer));
			return (NULL);
		line = ft_verify_stash(stash);
		if (line)
			return (line);
	}
}
