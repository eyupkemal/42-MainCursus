/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:20 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:21 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		*((unsigned char *)s) = 0;
		s++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	deneme[6] = "ahmet";
	printf("before : %s, ", deneme);
	ft_bzero(deneme, sizeof(deneme));
	printf("after : %s", deneme);
}
*/
