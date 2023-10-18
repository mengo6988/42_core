/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:34:49 by mho               #+#    #+#             */
/*   Updated: 2023/10/18 09:34:24 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(lst -> content);
	if (!new)
		return (NULL);
	res = new;
	lst = lst -> next;
	while (lst)
	{
		new -> next = ft_lstnew(lst -> content);
		new = new -> next;
		if (!new)
			return (NULL);
		lst = lst -> next;
	}
	(void)(*del);
	return (res);
}
