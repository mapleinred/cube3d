/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:06:30 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/12 15:51:44 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*i;

	i = malloc(nmemb * size);
	if (i == NULL)
		return (NULL);
	else 
		ft_bzero(i, nmemb * size);
	return (i);
}
