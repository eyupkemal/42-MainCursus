/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:55 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:56 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst -> content);
	free(lst);
}
/*
#include <stdio.h>
void ft_del(void *content)
{

	bzero(content, sizeof(content));
}
int	main()
{
	char l[] = "start";
	char s0[] = "student0";
	char s1[] = "student1";
	char s2[] = "student2";
	t_list *lst = ft_lstnew(l);
	t_list *student0 = ft_lstnew(s0);
	t_list *student1 = ft_lstnew(s1);
	t_list *student2 = ft_lstnew(s2);

	ft_lstadd_back(&lst, student0);
	ft_lstadd_back(&lst, student1);
	ft_lstadd_back(&lst, student2);
	ft_lstdelone(student1, ft_del);
	while(lst)
	{
		printf("%s \n",(char *)lst->content);
		lst = lst->next;
	}
}
*/
