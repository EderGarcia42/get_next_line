/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:48:08 by edegarci          #+#    #+#             */
/*   Updated: 2024/09/19 12:54:51 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_store(int fd, char *buffer)
{
	char	temp[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*temp_buffer;

	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	if (bytes_read == 0)
	{
		if (buffer == NULL || buffer[0] == '\0')
		{
			free(buffer);
			return (NULL);
		}
		temp[0] = '\0';
	}
	else
		temp[bytes_read] = '\0';
	temp_buffer = ft_strjoin(buffer, temp);
	free(buffer);
	return (temp_buffer);
}

char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + (buffer[i] == '\n'));
	return (line);
}

char	*save_rest(char *buffer)
{
	int		i;
	char	*rest;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	rest = ft_strdup(buffer + i + 1);
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_store(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
		return (NULL);
	buffer = save_rest(buffer);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening the file.\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
