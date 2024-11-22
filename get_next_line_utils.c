/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:43:40 by pitran            #+#    #+#             */
/*   Updated: 2024/11/21 13:39:17 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
    while(*(s))
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

size_t  ft_strlen(char *str)
{
    size_t  i;
    i = 0;
    
    while(str[i])
        i++;
    return i;
}
char    *ft_strdup(char *s)
{
    size_t  i;
    size_t  j;
    size_t  size;
    char    *dup;

    if (!s)
        return(NULL);

    size = ft_strlen(s);
    
    dup = (char *)malloc(sizeof(char) * (size + 1));
    if (!dup)
        return(NULL);
    i = 0;
    j = 0;
    while (s[i])
        dup[i++] = s[j++];
    dup[i] = '\0';
    return (dup);
}

char    *ft_substr(char *str, unsigned int start, size_t len)
{
    size_t  i;
    char    *substr;

    i = 0;
    if(!str)
        return(NULL);
    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr)
        return(NULL);
    while (str[start] && start < len)
        substr[i++] = str[start++];
    substr[i] = '\0';
    return(substr);
}

char    *ft_strjoin(char *base, char *append)
{
    size_t  i;
    size_t  j;
    size_t  joint_len;
    char    *joint;
    
    if(!base)
        return(append);
    joint_len = ft_strlen(base) + ft_strlen(append);
    joint = (char *)malloc(sizeof(char) * (joint_len + 1));
    if (!joint)
        return(NULL);
    i = 0;
    while (base[i])
    {
        joint[i] = base[i];
        i++;
    }
    j = 0;
    while (append[j])
        joint[i++] = append[j++];
    joint[i] = '\0';
    return(joint); 
}
/*
int main(void)
{
    char    *s1 = "les vaches";



    char    *s2 = " aiment brouter";
    char    *join = ft_strjoin(s1, s2);

    printf("The joint string is: %s\n", join);
}
*/
/*
int main(void)
{
    char    *str = "Il va pleuvoir après-demain";
    char    *substr = ft_substr(str, 0, 15);

    printf("The substring is: %s\n", substr);
}
*/
/*
int main(void)
{
    char    *to_dup = "";
    char    *duplicata = ft_strdup(to_dup);
    
    printf("The duplicata is : %s\n", duplicata);
    
}*/

/*
char    *get_line(int fd, char *line)
{
    char    *buffer;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    
    if (!buffer)
    {
        buffer = NULL;
        free (buffer)
    }

    read(fd, buffer, BUFFER_SIZE);

    if (read(fd, buffer, BUFFER_SIZE) < 0)
        return (NULL);  
}
*/
/*
#include <stdio.h>

int main(void)
{

    char    *str = "1234a678";
    char    letter = 'b';
    char    *result = ft_strchr(str, letter);

    if (result != NULL)
        printf("Caracter %c was found in position: %ld\n", letter, result - str + 1);
    else    
        printf("Caracter %c not found.\n", letter);
}
*/