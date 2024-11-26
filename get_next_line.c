/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:59:26 by pitran            #+#    #+#             */
/*   Updated: 2024/11/26 13:26:52 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



static char    *set_line(char *buffer)
{
    size_t    i;
    char    *line_left;
    
    i = 0;
    if (!buffer)
        return (NULL);
    while(buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    if(buffer[i] == '\0')
        return (NULL);
    if (buffer[i + 1] == '\0')
        return (NULL);
    line_left = ft_strdup(buffer + i + 1);
    if(!line_left)
        return(NULL);
    buffer[i + 1] = '\0';
    return(line_left);
}

char    *subline(int fd, char *line, char *buffer, char **line_left)
{
    ssize_t bread;
    char    *tmp;

    bread = 1;
    while (bread > 0)
    {
        ft_memset(buffer, 0, BUFFER_SIZE + 1);
        bread = read(fd, buffer, BUFFER_SIZE);
        if (bread == -1 || (bread == 0 && (!line || line[0] == '\0')))
			return (free(line), free(*line_left), *line_left = NULL, NULL);
        buffer[bread] = '\0';
        if(!line && !(line = ft_strdup("")))
            return(NULL);
        if(!(tmp = ft_strjoin(line, buffer)))
            return(NULL);
        free(line);
        line = tmp;
        if (ft_strchr(buffer, '\n'))
            break;
    }
    return(line);
}

char    *get_next_line(int fd)
{
    static char *line_left;
    char        *buffer;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(line_left);
        line_left = NULL;
        return(NULL);
    }
    line = (line_left) ? line_left : NULL;
    line_left = NULL;
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return(NULL);
    line = subline(fd, line, buffer, &line_left);
    free(buffer);
    if (!line)
        return(NULL);
    line_left = set_line(line);
    if(!line || line[0] == '\0')
        return(free(line),NULL);
    return (line);
}

