/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:42:22 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/22 18:50:28 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_uitoa(unsigned int n)
{
	char			*result;
	unsigned int	nb;
	int				len;

	nb = n;
	len = ft_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (nb == 0)
		result[0] = '0';
	result[len] = '\0';
	while (nb != 0)
	{
		result[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	write(1, result, ft_strlen2(result));
	free (result);
	return (ft_len(n));
}
