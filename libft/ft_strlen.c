/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:43:29 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/02/02 16:46:36 by ekaraogl         ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
//s dizisinin uzunlugunu hesaplar
