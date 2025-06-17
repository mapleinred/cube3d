/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:06:15 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/11 19:02:00 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void	printcharindex(unsigned int index, char *C)
{
	print("Character at index %u is : %c\n", index, *c);
}

int	main(void)
{
	char str[5] = "Hello";
	ft_striteri(str, &printcharindex);
	return (0);
}ft_striteri` applies function `f` to each character in the string `s`
passing both the character and its index as arguments to function f
*/
