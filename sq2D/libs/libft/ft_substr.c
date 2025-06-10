/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:52:29 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/15 13:08:51 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*newstr;
// 	size_t	i;
// 	size_t	j;

// 	newstr = (char *)malloc(sizeof(ft_strlen(s)) * (len + 1));
// 	if (!newstr)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			newstr[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	newstr[j] = '\0';
// 	return (newstr);
// }  MKO

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	j = 0;
	while (s[start] && j < len)
	{
		newstr[j] = s[start];
		start++;
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
