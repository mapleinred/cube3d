/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:57:37 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/13 12:13:02 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*lst = lst->next;move to the next node return lst;
 return a pointer to the last node
 function is used to find and return a pointer to the last 
 node in a linked list. It takes a pointer to the first node of the 
 list (lst) as its argument*/
