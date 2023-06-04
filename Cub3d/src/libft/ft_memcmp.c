/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:02:32 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:02:33 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < (n - 1))
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
			break ;
		index++;
	}
	return (((unsigned char *)s1)[index] - (((unsigned char *)s2)[index]));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*p1 = "bubir";
	char	*p2 = "buiki";

	printf("org : %d, mine : %d", memcmp(p1,p2,5), ft_memcmp(p1,p2,5));
}
*/
