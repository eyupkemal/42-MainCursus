/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:50 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:51 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*travel;

	if (*lst == NULL)
		*lst = new;
	else
	{
		travel = ft_lstlast(*lst);
		travel -> next = new;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*liste = ft_lstnew((void *)49);
	t_list	*tut;

	for (size_t i = 50; i < 55; i++)
	{
		ft_lstadd_back(&liste, ft_lstnew((void *)i));
	}
	tut = ft_lstlast(liste);
	printf("%c", (char)(tut -> content));
}
*/
