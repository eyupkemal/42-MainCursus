/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:02:46 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:02:47 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((unsigned char *)s)[counter] = c;
		counter++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*a = malloc(sizeof(char) * 5);
	char	*b = malloc(sizeof(char) * 5);
	char	src = 'A';

	printf("org : %s, ", memset(a, src, 5));
	printf("mine : %s", ft_memset(b, src, 5));
}
*/
