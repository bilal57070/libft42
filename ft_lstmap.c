/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:46:24 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/06 17:41:28 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nvlst;

	nvlst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	if (!nvlst)
		return (0);
	while (lst)
	{
		f(lst->content);
		nvlst = lst;
		del(lst->content);
		lst = lst->next;
		nvlst = nvlst->next;
	}
	return (nvlst);
}
