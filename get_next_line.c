/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:16:56 by ocviller          #+#    #+#             */
/*   Updated: 2025/05/18 16:40:43 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line_buffer(int fd, char *stash, char *buffer)
{
	int		bytes_read;
	char	*temp;

	if (!stash)
		stash = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
	}
	if (bytes_read < 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

char	*set_line(char *line)
{
	int		i;
	char	*stash;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		line[i] = '\0';
		return (NULL);
	}
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, stash, buffer);
	free(buffer);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	stash = set_line(line);
	return (line);
}

int main()
{
	int fd;
	char *line;

	fd = open("empty.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}