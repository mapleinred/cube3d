/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:26:48 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/17 08:40:29 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			i++;
		while (*str && *str != c)
			str++;
	}
	return (i);
}

static void	*ft_freewords(char **s, int i)
{
	while (i)
	{
		i--;
		free(s[i]);
	}
	free(s);
	return (0);
}

static int	ft_splitwords(char **result, char *str, char c)
{
	int	len;
	int	i;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	*result = malloc((len + 1) * sizeof(char));
	if (!*result)
		return (0);
	i = 0;
	while (i < len)
	{
		result[0][i] = str[i];
		i++;
	}
	result[0][i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*str;
	char	**result;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	result = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && !ft_splitwords(&result[i++], str, c))
			return (ft_freewords(result, i));
		while (*str && *str != c)
			str++;
	}
	result[i] = (NULL);
	return (result);
}

/*	`ft_split` splits a str `s` into multiple substrs separated by the char `c`
**	Returns an array of substrings (char **).
**
**	`count_strings` helper function
**	counts the number of substrs in the str `str` separated by the char `c`
**	Returns the number of substrs
**
**	`ft_singlestring` helper function
**	allocates memory for a substr and copies characters from `str`
**	into this newly allocated memory until the char `c` or end of string
**	Returns 1 if successful, 0 if unsuccessful
**
**	`free_strings`	helper function	
**	frees any previously allocated memory for the substrs
**	in case of error during the split operation
**	Returns a NULL pointer
*/

/*	Explanation
**	1. if str `s` is `NULL`, function returns `NULL`
**	2. str `s` is cast to a mutable string `str` (for navigation purposes)
**	3. malloc `result` (array of substrs), size from `count_strings` + 1
**	4. malloc fail check -> `NULL`
**	5. while loop: *str (until end of string)
**			<separator>
**		- if current character is `c`, skip till non-`c` or end of string
**			<substring>
**		- if non-`c` character is found
**			- call `ft_singlestring` to malloc & fill substr
**			- if `ft_singlestring` fails, execute `free_strings` -> `NULL`
**		- move the ptr `str` forward till next `c` or end of string
**	6. set the final element of `result` arr to `NULL` to mark end of arr
**	7. Return `result` (array of substrings)
*/
