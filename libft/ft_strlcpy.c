/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:59:56 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/02/07 14:33:22 by ekaraogl         ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

//dstsize -src dizesinden dst ye 1 karaktere kadar kopyalar
//dstsize 0 degilse sonuç null sonlandırıyor
//parametreler
//kopyalanacak kader dizisi
//kopyalanacak kaynak dize
//kaderdeki toplam bayt sayısı

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
