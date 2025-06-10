/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:18:19 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/10 18:50:26 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
/*The function starts by checking if both s1 and set are non-null 
 * (not NULL) to ensure they are valid inputs.
 * 
 * It enters the first while loop to find the first character in s1 
 * that is not in the set set. In this case, it skips the leading 
 * spaces and advances s1 to point to the first non-space character.
 *
 * After the first while loop, s1 points to "Hello, World! ", 
 * as the leading spaces have been trimmed.
 *
 * Next, it calculates the length of the trimmed portion 
 * of s1 using ft_strlen, which is 13 (the length of "Hello, World!").
 *
 * It enters the second while loop to find the last character in 
 * the trimmed portion of s1 that is not in the set set. In this 
 * case, it moves i backward to exclude the trailing spaces.
 *
 * After the second while loop, i is 11, representing the new 
 * length of the trimmed string.
 *
 * Finally, it calls ft_substr to create a new string that contains 
 * the trimmed portion of s1 from index 0 to i. The resulting 
 * string is "Hello, World!".
 *
 * So, the final result returned by the ft_strtrim function is the 
 * string "Hello, World!", with the leading and trailing spaces removed.
 */
