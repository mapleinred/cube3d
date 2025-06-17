/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:44:29 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/15 13:19:57 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}
/*The  strchr()  function  returns  a pointer to the first occurrence of the
character c in the string s.
   The strchr() and strrchr() functions return a pointer to the matched
   character or NULL if the character  is not found.  The terminating null
   byte is considered part of the string, so that if c is specified as '\0', 
   these functions return a pointer to the terminator.
- c is cast to unsigned char to ensure that comparison is valid even
for ASCII character. 
- signed char = -128 to 127. unsigned char = 0 - 255. 
-so when we pass an int value to function using char (where the value is 
outside the range), it might be intepreted as -ve number if the char is signed
*/
