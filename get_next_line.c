/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:16 by edegarci          #+#    #+#             */
/*   Updated: 2024/09/25 17:29:19 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
 * read_and_store: Reads from the file descriptor and appends the content 
 * to the existing 'storage' until a newline character is found or End of File 
 * is reached.
 * It returns the updated 'storage' containing the newly read content.
 */
char	*read_and_store(int fd, char *storage)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readbytes;
	char	*tmp;

	readbytes = 1;
	while (!ft_strchr(storage, '\n') && readbytes != 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes < 0)
		{
			free(storage);
			return (NULL);
		}
		if (readbytes == 0)
			break ;
		buffer[readbytes] = '\0';
		tmp = ft_strjoin(storage, buffer);
		if (!tmp)
		{
			free(storage);
			return (NULL);
		}
		storage = tmp;
	}
	return (storage);
}

/* 
 * leftover: Extracts the remaining content in 'storage' after the newline 
 * character.
 * It returns the remaining content after freeing the previous 'storage'.
 */
char	*leftover(char *storage)
{
	char	*leftover;
	int		i;
	int		j;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	leftover = malloc(sizeof(char) * (ft_strlen(storage) - i));
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
 * create_line: Extracts the line from 'storage' up to the newline character
 * (or the end of the string if no newline is found). It returns the line.
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
	line = malloc(sizeof(char) * (i + (storage[i] == '\n') + 1));
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
 * get_next_line: Main function that returns the next line from the file 
 * descriptor.
 * It reads data using 'read_and_store', extracts the line with 'create_line',
 * and prepares the leftover content using 'leftover'. 
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

/* MAIN NORMAL */
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

/* MAIN CON TIEMPO Y ARGV*/
/* #include <sys/time.h>

 int	main(int ac, char **av) {
		(void)ac;
		struct timeval start, end;
		gettimeofday(&start, NULL);
	int fd = open(av[1], O_RDONLY);

	char *line = get_next_line(fd);

	while (line) {


		printf ("%s", line);
		line = get_next_line(fd);
	}
gettimeofday(&end, NULL);
	printf("time spent ==> %ld\n", (end.tv_sec - start.tv_sec) * 1000 + 
	(end.tv_usec - start.tv_usec) / 1000);

		return (0);} */

/* TEST */
/* 		#include <stdio.h>
#include <fcntl.h>

int main()
{
    FILE *fp = fopen("test.txt", "w");
    for(int i=0; i<10000; i++)
    {
        fprintf(fp, "a");
    }
} */