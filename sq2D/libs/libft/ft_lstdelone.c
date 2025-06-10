/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:33:35 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/13 18:04:33 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
`ft_lstdelone` frees the memory of the node's content
using the function `del` and frees the node
The memory of `next` must not be freed

`t_list *lst`: the node to free
`del`: the address of the function used to delete the content

check !lst or !del NULL (prevent error, just return) ->
calls `del` to free the content of the node -> free `lst` node itself

intentionally designed to delete only a single node and its content
without affecing subsequent nodes
IMPT:
make sure to have another reference to the `next` node b4 `ft_lstdelone`
else the node becomes orphaned and we get a memleak

sample `del` function:
void del(void *content)
{		
	free(content);
}*/
