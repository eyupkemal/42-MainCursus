/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:21 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:22 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = (void *)malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}
/*
#include <stdio.h>
int	main()
{
	int *ptr;
	int *ft_p;
	int i;
	int j;
	ft_p = (int *)ft_calloc(2, 2);
	ptr = (int *)calloc(2, 2);
	i = 0;
	while (i < 5)
	{
		printf("org_addres:%p | org_value:%i\n", (ptr + i), *(ptr + i));
		i++;
	}
	j = 0;
	while (j < 5)
	{
		printf("ft_addres:%p | ft_value:%i\n", (ft_p + j), *(ft_p + j));
		j++;
	}
}
*/
