/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:45:29 by xzhang            #+#    #+#             */
/*   Updated: 2024/08/20 14:45:42 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_strleni(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-(unsigned char)s2[i]);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*result;
	size_t	max_size;

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (ft_calloc(1, new_size));
	result = ft_calloc(1, new_size);
	if (!result)
		return (NULL);
	if (new_size >= old_size)
		max_size = old_size;
	else
		max_size = new_size;
	ft_memmove(result, ptr, max_size);
	free(ptr);
	return (result);
}

double	ft_atod(char *str)
{
	int		intvalue;
	double	result;
	char	*dp;
	double	fraction;

	intvalue = ft_atoi(str);
	result = (double)intvalue;
	fraction = 0.1;
	dp = ft_strchr(str, '.');
	if (dp)
		dp++;
	while (dp && *dp >= '0' && *dp <= '9')
	{
		result += (*dp - '0') * fraction;
		fraction /= 10.0;
		dp++;
	}
	return (result);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	s2 = (char *)malloc(n + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
