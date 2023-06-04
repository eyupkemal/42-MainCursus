/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:03:24 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:03:36 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	c;
	unsigned int	d;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	c = ft_strlen(dest);
	d = 0;
	while (src[d] != '\0' && c + 1 < size)
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[d]));
}
/*
#include <stdio.h>
int	main()
{
	char a[] = "ahmet";
	char b[] = "eryilmaz";
	printf("return %zu -> %s", ft_strlcat(a, b, 9), a);
}
*/
