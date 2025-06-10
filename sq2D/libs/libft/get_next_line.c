/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:59:25 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/29 13:34:09 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_readfile(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	tmp = ft_readline(str[fd]);
	str[fd] = ft_movestr(str[fd]);
	if (!*tmp)
	{
		free (tmp);
		return (NULL);
	}
	return (tmp);
}
/*
read from file descriptor fd and concatenate what it read to given str
1) declare temporary string tmp and allocate memory buffer size+1(\0)
2) return null if memory allocation failed
3) intialize bytes to 1 to store the words read, meet while condition
   and run once. 
4) run the loop while \n not found and not yet end of file (bytes = 0)
5) the read result is the bytes that had read. store to tmp. 
6) tmp is then add null and append to new_str using strjoin.
7) return null if bytes <=0 (reached end of file/error-1), and free the
   tmp and str
8) return the str that contained the readed string.
*/

char	*ft_readfile(int fd, char *str)
{
	char	*tmp;
	int		fdread;

	fdread = 1;
	tmp = (char *)malloc(sizeof(char) * (1 + BUFFER_SIZE));
	if (!tmp)
		return (NULL);
	while (!(ft_strchr1(str, '\n')) && fdread != 0)
	{
		fdread = read(fd, tmp, BUFFER_SIZE);
		if (fdread == -1)
		{
			free(tmp);
			free(str);
			str = NULL;
			return (NULL);
		}
		tmp[fdread] = '\0';
		str = ft_strjoin1(str, tmp);
	}
	free(tmp);
	return (str);
}
/*
read from file descriptor fd and concatenate what it read to given str
1) declare temporary string tmp and allocate memory buffer size+1(\0)
2) return null if memory allocation failed
3) intialize bytes to 1 to store the words read, meet while condition
and run once. 
4) run the loop while \n not found and not yet end of file (bytes = 0)
5) the read result is the bytes that had read. store to tmp. 
6) tmp is then add null and append to new_str using strjoin.
7) return null if bytes <=0 (reached end of file/error-1), and free the
tmp and st
8) return the str that contained the readed string. 
*/

char	*ft_readline(char *fullstr)
{
	int		i;
	char	*line;

	i = 0;
	if (!fullstr)
		return (NULL);
	while (fullstr[i] && fullstr[i] != '\n')
		i++;
	if (fullstr[i] == '\n')
		i++;
	line = (char *)malloc(1 + i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (fullstr[i] && fullstr[i] != '\n')
	{
		line[i] = fullstr[i];
		i++;
	}
	if (fullstr[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
/*
(full_str[i] && full_str[i] != '\n') is often preferred as 
it provides an additional safety check (full_str[i]) to avoid 
accessing memory beyond the end of the string.
extract single line from the full_str buffer read from read_file function
1) allocate memory for the str until \n plus 2 (\n+'\0')
2) copy from the full_str to line, for the length of i
3) add the \n to te line extracted and null terminate it.
*/

char	*ft_movestr(char *str)
{
	int		i;
	int		j;
	char	*restof;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str && str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	restof = (char *)malloc(sizeof(char) * (ft_strlen1(str) - i + 1));
	if (!restof)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		restof[j++] = str[i++];
	restof[j] = '\0';
	free(str);
	return (restof);
}
/*
get the rest of full_str after extracted out the line
1)i++ until nxt line, then allocate memory for balance space+1
2) i++ to skip the \n, then copy the balance of full_str to restof
3) null terminate the restof and return it. 
4) full_str is free and this function will return the restof to new_str
*/

/*char	*addtmptostr(char *str, char *tmp)
{
	char	*swap;

	if (str == NULL)
	{
		str = ft_substr("", 0, 1);
		free(str);
	}
	swap = ft_strjoin(str, tmp);
	str = ft_strjoin("", swap);
	free(swap);
	swap = NULL;
	return (str);
} str = addtmptostr(str, tmp); */
