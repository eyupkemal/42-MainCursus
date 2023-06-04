/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:04:32 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:04:33 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*ret;
	size_t	index;

	if (ft_strlen(str) < n)
		n = ft_strlen(str);
	ret = malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	index = 0;
	while (index < n)
	{
		ret[index] = str[index];
		index++;
	}
	ret[index] = 0;
	return (ret);
}
