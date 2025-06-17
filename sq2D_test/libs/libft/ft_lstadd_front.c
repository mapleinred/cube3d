/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:05:49 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/13 11:47:37 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
`ft_lstadd_front``
t_list **list`:pointer to pointer pointing to the head node of the List
`t_list *new`:pointer to the node to be added into the List
add a new element (node) to the front of a linked list. 
This function allows you to prepend a new element to an existing linked list, 
making the new element the new head of the list.
*/
