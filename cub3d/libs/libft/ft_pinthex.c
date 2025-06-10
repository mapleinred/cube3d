/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pinthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:12:00 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/24 13:54:49 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pinthex(unsigned int n, char c)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_putchar2(hex[n]);
		count++;
	}
	else
	{
		count += ft_pinthex(n / 16, c);
		count += ft_pinthex(n % 16, c);
	}
	return (count);
}
/*
The ft_pinthex function appears to be a recursive function for printing 
hexadecimal numbers.
unsigned int n: This is the unsigned integer that you want to convert and 
print in hexadecimal format.
char c: This character determines whether the hexadecimal representation 
should use lowercase ('x') or uppercase ('X') letters.
It initializes a character pointer hex to point to the hexadecimal digit 
characters.Depending on the value of c, 
it sets hex to point to either lowercase hexadecimal characters
('0123456789abcdef') or uppercase hexadecimal characters
('0123456789ABCDEF').

It initializes an integer variable count to 0. This variable is used to keep 
track of the number of characters printed.
The function then checks if the input n is less than 16 
(the base of hexadecimal representation). 

If n is less than 16, it means that n is a single hexadecimal digit, 
so it directly prints that digit using ft_putchar and increments the 
count by 1.
If n is greater than or equal to 16, the function enters the recursive part. 
It first calls itself with n / 16 as the argument. This effectively 
divides n by 16, which corresponds to shifting one hexadecimal 
digit to the right.

After printing the first digit, it then calls itself with n % 
16 as the argument. 
This calculates the remainder when n is divided by 16, which 
represents the rightmost hexadecimal digit.

The count variable is updated with the sum of the counts returned by the 
recursive calls. 
This keeps track of how many characters were printed during the entire process.

The function eventually returns the total count of characters printed, 
which is the count of characters needed to represent the hexadecimal number.

The recursion continues until n becomes less than 16, at which point it starts 
returning and printing the hexadecimal digits from right to left. 
This process ensures that the hexadecimal representation of n is 
correctly printed.
*/
