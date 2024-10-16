/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:41 by edegarci          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:43 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *storage, const char *buffer)
{
	int		i;
	int		j;
	char	*str;

	if (!storage)
	{
		storage = (char *)malloc(1 * sizeof(char));
		storage[0] = '\0';
	}
	if (!storage || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(storage) + ft_strlen(buffer) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (storage[++i])
		str[i] = storage[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(storage);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	if (!s)
		return (NULL);
	ch = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == ch)
		return ((char *)&s[i]);
	return (NULL);
}
