/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:08:32 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/13 17:06:41 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (! lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
`ft_lstiter` iterates the LL `lst` and applies the function `f` on the
content of each node

`t_list *lst`: the address of a pointer to a node
`f'the address of the function used the iterate on the list

basically strmapi but different things
while there's still nodes, apply the function on the content of the LL node
navigate to the next node
exit while loop when there's no more nodes */
