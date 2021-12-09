/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:32:16 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/09 17:01:30 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2, int i, int n)
{
	char	*buffer;

	if (s1 == NULL || s2 == NULL)
		return (ft_mallocprotect(s1, s2));
	buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		buffer[i + n] = s2[n];
		n++;
	}
	buffer[i + n] = '\0';
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i - 1] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_rest(char *buffer)
{
	char	*rest;
	int		i;
	int		n;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(buffer) - i));
	if (rest == NULL)
		return (NULL);
	n = 0;
	while (buffer[i] != '\0')
		rest[n++] = buffer[++i];
	free(buffer);
	rest[n] = '\0';
	if (rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		*line;
	char		*read_line;
	static char	*buffer;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line = malloc(sizeof(char) * (BUFFER_SIZE));
	if (read_line == NULL)
		return (NULL);
	bytes = 1;
	while (bytes && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, read_line, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, read_line, 0, 0);
	}
	free(read_line);
	line = get_line(buffer);
	buffer = get_rest(buffer);
	return (line);
}

int	main(void)
{
	char	*str;
	int	fd;

	fd = open("toto.txt", O_RDONLY);
	if (!fd)
		return (1);
	while (str = get_next_line(fd))
	{
		//printf("%s", str);
		free(str);
	}
	return (0);
}
