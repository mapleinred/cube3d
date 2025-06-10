/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:08:14 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/15 15:14:23 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	t_list	*newcontent;

	newlist = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		newcontent = f(lst->content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			del(newcontent);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
/*`ft_lstmap` iterates the list `lst`
and applies the function `f` on the content of each node.
Creates a new list resulting of successive applications of the function `f`
The `del` function is used to delete the content if needed

`t_list *lst`: the address of a pointer to a node
`f`the address of the function used the iterate on the list
`del` the address of the function used to dlt the content of a node if need

Returns the new list
NULL if malloc fail

The function transverses the original list `lst`
creates new nodes with the result of applying `f` to the content of each node
appends these new nodes to the new list
If there's a failure in creating a new node, the function cleans up any node
that were successfully created before the failure, then returns NULL*/
