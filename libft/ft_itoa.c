/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:15:31 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/02/15 17:16:34 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findlen(long nn, int len)
{
	while (nn > 9)
	{
		len++;
		nn /= 10;
	}
	return (len);
}

static void	putnumber(char *ml, int len, long nn, int neg)
{
	ml[len--] = '\0';
	while (nn > 9)
	{
		ml[len] = (nn % 10) + 48;
		len--;
		nn /= 10;
	}
	ml[len--] = (nn % 10) + 48;
	if (neg == -1)
		ml[len] = '-';
}

char	*ft_itoa(int n)
{
	int		neg;
	long	nn;
	int		len;
	char	*ml;

	nn = (long)n;
	neg = 1;
	len = 1;
	if (nn < 0)
	{
		neg = -1;
		nn *= -1;
		len++;
	}
	len = findlen(nn, len);
	ml = (char *)malloc(sizeof(char) * (len + 1));
	if (!ml)
		return (NULL);
	putnumber(ml, len, nn, neg);
	return (ml);
}
