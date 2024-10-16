/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:18:32 by edegarci          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:45 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*leftover(char *storage);
char	*create_line(char *storage);
char	*read_and_store(int fd, char *storage);

#endif
