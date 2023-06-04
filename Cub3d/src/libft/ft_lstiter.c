/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:01:18 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:01:19 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
/*
#include <stdio.h>
void	fa(void *content)
{
	//ft_memset(content, 'a', 0);
	memset(content, 48, strlen(content));
}
int	main(void)
{
	char a[] = "ff";
	char b[] = "gg";
	char c[] = "yy";
	t_list	*liste = ft_lstnew(a);
	t_list	*tut;
	size_t	i;

	ft_lstadd_back(&liste, ft_lstnew(b));
	ft_lstadd_back(&liste, ft_lstnew(c));


	//eskisini yazdir
	printf("eski :\n");
	tut = liste;
	for (i = 49; i < 52; i++)
	{
		printf("%s - ",(tut -> content));
		tut = tut -> next;
	}

	ft_lstiter(liste, fa);
	//yenisini yazdir
	printf("\nyeni :\n");
	for (i = 49; i < 52; i++)
	{
		printf("%s - ",(liste -> content));
		liste = liste -> next;
	}
}
*/
