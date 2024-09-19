/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:48:04 by edegarci          #+#    #+#             */
/*   Updated: 2024/09/17 13:05:58 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42

# include <fcntl.h> // Para open y O_RDONLY
# include <stddef.h> // Para size_t y NULL
# include <stdio.h> // Para printf
# include <stdlib.h> // Para malloc y free
# include <unistd.h> // Para read y close

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
