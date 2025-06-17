/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:00:49 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/12 15:44:50 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*x;
	char	*y;
	size_t	i;

	i = 0;
	x = (char *)s1;
	y = (char *)s2;
	while (i < n)
	{
		if (x[i] != y[i])
			return ((unsigned char)x[i] - (unsigned char)y[i]);
		i++;
	}
	return (0);
}
