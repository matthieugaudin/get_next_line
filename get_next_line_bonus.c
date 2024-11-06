/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:39 by mgaudin           #+#    #+#             */
/*   Updated: 2024/11/04 15:01:15 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_update_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i])
		line[i + 1] = '\0';
	return (line);
}

char	*ft_clean_stash(char *pstash)
{
	char	*new_stash;
	size_t	is_over;
	size_t	len;
	size_t	i;

	i = 0;
	while (pstash[i] != '\0' && pstash[i] != '\n')
		i++;
	len = ft_strlen(pstash);
	is_over = pstash[i] == '\0';
	new_stash = ft_substr(pstash, i + 1, len - i - is_over);
	if (!new_stash)
		return (NULL);
	else
		return (new_stash);
}

void	ft_update_stash(char **pstash, char *buffer)
{
	char	*tmp;

	tmp = *pstash;
	*pstash = ft_strjoin(*pstash, buffer);
	free(tmp);
}

char	*ft_fill_stash(int fd, char **pstash, char *buffer)
{
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
		if (!*pstash)
			*pstash = ft_strdup("");
		if (!*pstash)
			return (NULL);
		ft_update_stash(pstash, buffer);
		if (!*pstash)
			return (NULL);
		if (bytes_read == 0 || ft_strchr(*pstash, '\n'))
			break ;
	}
	return (*pstash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_fill_stash(fd, &stash[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line || *stash[fd] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_clean_stash(stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_update_line(line);
	return (line);
}
