/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:03:15 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:03:16 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	index;
	size_t	len;

	len = ft_strlen(s) + 1;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	index = 0;
	while (index < len)
	{
		ret[index] = s[index];
		index++;
	}
	return (ret);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*src = "bunu dupla";
	printf("%s -> %s", src, ft_strdup(src));
}
*/
