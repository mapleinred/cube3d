/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:04:37 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/22 18:44:44 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numsize(int n)
{
	int			len;
	long int	nbr;

	nbr = n;
	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	ft_itoa2(int n)
{
	char		*s;
	int			len;
	long int	nbr;

	nbr = n;
	len = ft_numsize(n);
	s = malloc(sizeof(char) * (len + 1));
	if (nbr == 0)
		s[0] = '0';
	else if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	s[len] = '\0';
	while (nbr > 0)
	{
		len--;
		s[len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	write(1, s, ft_strlen2(s));
	free(s);
	return (ft_numsize(n));
}
/*writes a signed integer to decimal representation %d print a 
decimal (base 10) number.%i print an integer in base 10.*/
