/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:28:51 by pitran            #+#    #+#             */
/*   Updated: 2024/11/26 13:05:32 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

char        *ft_strchr(const char *s, int c);
size_t      ft_strlen(char *str);
char        *ft_strdup(char *s);
char        *ft_substr(char *str, unsigned int start, size_t len);
char        *ft_strjoin(char *base, char *append);
char	    *subline(int fd, char *subline, char *buffer, char **line_left);
char	    *get_next_line(int fd);
void    	*ft_memset(void *s, int c, size_t n);

#endif