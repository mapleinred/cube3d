/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:26:39 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/15 07:52:48 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	j;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little [0])
		{
			j = 0;
			while (big[i + j] == little[j] && (i + j) < len)
			{
				if (j == little_len - 1)
					return ((char *)(big + i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
/* The strnstr() function locates the first occurrence of the null-terminated 
string little in the string big, where not more than len characters are 
searched.  Charac‐ters that appear after a ‘\0’ character are not searched. 
Since the strnstr()function is a FreeBSD specific API, it should only be used 
when portability is not a concern.*/
