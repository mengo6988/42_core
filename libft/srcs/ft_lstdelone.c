/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:59:39 by mho               #+#    #+#             */
/*   Updated: 2023/10/18 08:11:33 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	tmp;

	if (!lst || !del)
		return ;
	tmp = lst -> next;
	del(lst -> content);
	free(lst);
	lst = tmp;
}
