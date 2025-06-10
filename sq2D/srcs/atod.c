/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:40:03 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/16 15:40:07 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sq2d.h"

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
