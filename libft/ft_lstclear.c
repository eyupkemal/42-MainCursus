/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:47:10 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/02/24 19:53:29 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*crr;
	t_list	*next;

	if (!lst)
		return ;
	crr = *lst;
	while (crr)
	{
		next = crr->next;
		ft_lstdelone(crr, del);
		crr = next;
	}
	*lst = NULL;
}
