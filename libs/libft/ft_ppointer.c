/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:13:33 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/24 15:28:27 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_phexapointer(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n < 16)
	{
		ft_putchar2(hex[n]);
		count++;
	}
	else
	{
		count += ft_phexapointer(n / 16);
		count += ft_phexapointer(n % 16);
	}
	return (count);
}

int	ft_ppointer(unsigned long n)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putchar2('0');
	ft_putchar2('x');
	return (ft_phexapointer(n) + 2);
}
/*
print the hexadecimal representation of an unsigned long 
pointer (n) with the "0x" prefix

In the function, define a character array hex containing hexadecimal 
digits and initialize a counter variable count to 0.

check if n is less than 16 (the number of hexadecimal digits). 
If n is less than 16, it means you have a single-digit 
hexadecimal number to print.

If n is less than16, you use putchar to print the corresponding 
hexadecimal digit from the hex array, and increment 
the count variable to keep track of the number of characters printed.

If n is greater than or equal to 16,enter the else block. Here, 
perform a recursive call to phexapointer with n/16, which represents 
the high-order digit of the hexadecimal number.

also perform a recursive call to ft_phexapointer with n % 16, 
which represents the low-order digit of the hexadecimal number.

The recursion continues until n becomes less than 16, and the 
function returns from the recursive calls.

The counts from the recursive calls are accumulated 
in the count variable.

Finally, the function returns the total count of characters printed.

In the ft_ppointer function, you first check if the input pointer 
n is equal to 0.If it is,write "(nil)" to the standard output and return 5, 
which is the length of "(nil)".

Otherwise,print "0x" to indicate the start of the hexadecimal 
representation, and call ft_phexapointer(n) to print the actual 
hexadecimal digits and accumulate the count.add 2 to the count for 
the "0x" prefix and return the total 
count of characters printed.
*/
