/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:04:33 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:04:34 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_strrcmp(char *src, char *dest)
{
	int	srci;
	int	desti;

	srci = ft_strlen(src) - ft_strlen(dest);
	desti = 0;
	if (srci <= 0)
		return (0);
	while (src[srci] && dest[desti])
	{
		if (src[srci] != dest[desti])
			break ;
		srci++;
		desti++;
	}
	return (((unsigned char *)src)[srci] - ((unsigned char *)dest)[desti]);
}
