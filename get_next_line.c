/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:39 by mgaudin           #+#    #+#             */
/*   Updated: 2024/10/30 12:19:38 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_clean_stash(char **pstash)
{
	char	*tmp;

	tmp = ft_strchr(*pstash, '\n');
	*pstash = tmp + 1;
}

char	*ft_fill_stash(int fd, char **pstash, char *buffer)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*pstash);
			*pstash = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (*pstash == NULL)
			*pstash = ft_strdup("");
		tmp = *pstash;
		*pstash = ft_strjoin(*pstash, buffer);
		free(tmp);
		if (ft_strchr(*pstash, '\n') || bytes_read == 0)
			break ;
	}
	return (*pstash);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char		*line;
	char		*buffer;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = ft_fill_stash(fd, &stash, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	ft_clean_stash(&stash);
	return (NULL);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
}