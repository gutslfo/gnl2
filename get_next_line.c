/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:37:26 by pitran            #+#    #+#             */
/*   Updated: 2024/11/23 18:49:14 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line(char *buffer)
{
	size_t	i;
	char	*line_left;
	
	i = 0;
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if(buffer[i] == '\0' || buffer[1] == '\0')
		return (NULL);
	line_left = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1);
	if(!line_left)
		return(NULL);
	buffer[i + 1] = '\0';
	return(line_left);
}

char	*subline(int fd, char *line, char *buffer,char **line_left)
{
	ssize_t	bread;
	char	*tmp;
	
	bread = 1;
  	while(bread > 0)
  	{
    	bread = read(fd, buffer, BUFFER_SIZE);
    	if (bread == -1)
		{
			free(line);
			free(*line_left);
			*line_left = NULL;
   	   		return(NULL);
		}
		else if (bread == 0)
		{
			free(*line_left);
			*line_left = NULL;
			break;
		}
		buffer[bread] = '\0';
		if(!line && bread > 0)
			line = ft_strdup("");
		tmp = ft_strjoin(line, buffer);
		free(line);
		line = tmp;
		if(!line)
			return(NULL);
		if (ft_strchr(buffer, '\n'))
			break;
 	}
	return (line);
}


char	*get_next_line(int fd)
{
	static char *line_left;
	char        *buffer;
	char        *line;

	line = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
    	return(NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
  	{
		free(line_left);
   		free(buffer);
    	line_left = NULL;
    	buffer = NULL;
    	return(NULL);
  	}
	if (line_left)
    {
        line = ft_strdup(line_left);
        free(line_left);
        line_left = NULL;
    }
	if(!line_left)
  		line = subline(fd, line, buffer, &line_left);
  	free(buffer);
  	buffer = NULL;
  	if (!line)
    	return(NULL); 
 	line_left = set_line(line);
	if(line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
  	return(line);
}
/*
int main()
{
	int fd = open("multiple_nl.txt", O_RDONLY);
	int i;

	i = 1;
	while (i < 10)
	{
		printf("Line %d : %s\n", i, get_next_line(fd));
		i++;
	}
	return 0;
}
*/

