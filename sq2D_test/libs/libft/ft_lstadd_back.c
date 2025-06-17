/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:13:21 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/13 12:20:23 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
`ft_lstadd_back` adds the node `new` at the end of the list
t_list last (to be assigned the last node)
if *lst == NULL, assign new to *lst
ELSE
uses the `ft_lstlast` to find the LAST NODE in the list
then point its next field to the new node.*/
