/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:42 by mgaudin           #+#    #+#             */
/*   Updated: 2024/10/30 17:08:25 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ps;

	ps = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ps)
		return (ps);
	i = 0;
	while (s[i])
	{
		ps[i] = s[i];
		i++;
	}
	ps[i] = 0;
	return (ps);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ps;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	while (i < len && start + i < s_len && s[start + i])
		i++;
	ps = (char *)malloc((i + 1) * sizeof(char));
	if (!ps)
		return (NULL);
	i = 0;
	while (i < len && start + i < s_len && s[start + i])
	{
		ps[i] = s[start + i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
