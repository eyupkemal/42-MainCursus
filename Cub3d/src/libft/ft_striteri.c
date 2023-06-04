/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:03:19 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:03:20 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index;

	index = 0;
	if (s)
	{
		while (s[index])
		{
			f(index, &s[index]);
			index++;
		}
	}
}
/*
#include <stdio.h>
void	funct(unsigned int a, char *b)
{
	*b = *b+a;
}
int main()
{
	char dizi[] = "aaaaaaaaaaaaaaaa";
	ft_striteri(dizi, funct);
	printf("%s",dizi);
}
*/
