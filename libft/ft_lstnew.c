/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:29:36 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/02/24 19:21:07 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cntn;

	cntn = (t_list *)malloc(sizeof(t_list));
	if (!cntn)
		return (NULL);
	cntn->content = content;
	cntn->next = NULL;
	return (cntn);
}
