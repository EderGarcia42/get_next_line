/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:16 by edegarci          #+#    #+#             */
/*   Updated: 2024/09/24 12:57:27 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
/*
 * Reads from the file descriptor `fd` and stores the contents in `storage`.
 * It reads until a newline character is found or EOF is reached.
 * Returns the updated `storage` with the new contents.
 */
char	*read_and_store(int fd, char *storage)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readbytes;

	readbytes = 1;
	while (!ft_strchr(storage, '\n') && readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free(storage);
			return (NULL);
		}
		if (readbytes == 0)
			break ;
		buffer[readbytes] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (NULL);
	}
	return (storage);
}

/*
 * Extracts the leftover string after the first newline character from `storage`.
 * If there is no newline, it frees `storage` and returns NULL.
 * Returns the remaining string after the newline.
 */
char	*leftover(char *storage)
{
	char	*leftover;
	int		i;
	int		j;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	leftover = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!leftover)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		leftover[j++] = storage[i++];
	leftover[j] = '\0';
	free(storage);
	return (leftover);
}

/*
 * Creates a line from `storage` up to the first newline character.
 * Allocates memory for the line and returns it.
 * If `storage` is empty, returns NULL.
 */
char	*create_line(char *storage)
{
	char	*line;
	int		i;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/*
 * Main function to get the next line from the file descriptor `fd`.
 * Uses a static variable `storage` to keep track of leftover data between calls.
 * Returns the next line or NULL if no more lines are available.
 */
char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	storage = read_and_store(fd, storage);
	if (!storage || !*storage)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	line = create_line(storage);
	storage = leftover(storage);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
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
