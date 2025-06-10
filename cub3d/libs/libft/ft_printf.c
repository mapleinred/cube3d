/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:29:52 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/24 15:05:45 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checktype(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = ft_itoa2(va_arg(args, int));
	else if (c == 's')
		count = (ft_putstr2(va_arg(args, char *)));
	else if (c == 'c')
		count = (ft_putchar2(va_arg(args, int)));
	else if (c == '%')
		count = (ft_putchar2('%'));
	else if (c == 'x' || c == 'X')
		count = (ft_pinthex(va_arg(args, unsigned int), c));
	else if (c == 'u')
		count = (ft_uitoa(va_arg(args, unsigned int)));
	else if (c == 'p')
		count = (ft_ppointer(va_arg(args, unsigned long)));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_checktype(str[i], args);
			i++;
		}
		else
		{
			ft_putchar2(str[i]);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}
/*
ft_checktype function appears to be responsible for handling different format 
specifiers in ft_printf implementation. It should correctly process various 
format specifiers and return the count of characters printed. Here's a summary 
of how each specifier is handled:

If the specifier is 'd' or 'i', it calls ft_itoa to convert the next argument 
(presumed to be an integer) into a string and returns the count of 
characters printed.

If the specifier is 's', it calls ft_putstr to print the next argument 
(presumed to be a string) and returns the count of characters printed.

If the specifier is 'c', it calls ft_putchar to print the next argument 
(presumed to be a character) and returns 1, as a single character is printed.

If the specifier is '%', it calls ft_putchar to print '%' and returns 1.

If the specifier is 'x' or 'X', it calls ft_pinthex to print the next argument 
(presumed to be an unsigned int) as a hexadecimal number and returns the 
count of characters printed.

If the specifier is 'u', it calls ft_uitoa to convert the next argument 
(presumed to be an unsigned int) into a string and returns the count of 
characters printed.

If the specifier is 'p', it calls ft_ppointer to print the next argument 
(presumed to be an unsigned long representing a pointer) as a hexadecimal 
pointer and returns the count of characters printed.

If none of the above specifiers match, it returns 0, 
indicating that no valid specifier was found.

ft_printf function iterates through the format string, and for each '%' 
character encountered, it calls ft_checktype to handle the specifier and 
accumulate the count of characters printed. For characters that are 
not '%' (regular characters), it simply prints them using ft_putchar and 
increments the count accordingly.
*/
