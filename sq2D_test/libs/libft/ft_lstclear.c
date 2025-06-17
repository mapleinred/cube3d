/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:44:14 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/13 18:04:05 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
/*
`ft_lstclear` deletes and frees the given node
and every successor of that node

`lst`: the address of the pointer to a node
`del`: the address of the function used to delete the content of the node

Tranverses the list, deleting & freeing each node content using delone
while there are still nodes in the LL,
store the next node's address in `temp` from (*lst)->next
use `ft_delone` to delete the current node
update the list pointer to the next node using *lst = temp (GG GO NEXT)
ends when no more nodes:
*lst already points to NULL, since the latest (*lst)->next is NULL
*/
