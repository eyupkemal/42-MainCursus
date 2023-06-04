/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:48 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:49 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arraylen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	ft_10base(int us)
{
	int	ret;

	ret = 1;
	while (us > 0)
	{
		ret *= 10;
		us--;
	}
	return (ret);
}

static char	*maxmin(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		lenght;
	int		index;

	lenght = ft_arraylen(n);
	index = 0;
	if (n == 0 || n == -2147483648)
		return (maxmin(n));
	ret = malloc(sizeof(char) * lenght + 1);
	if (!ret)
		return (NULL);
	if (n < 0 && lenght--)
	{
		ret[index++] = '-';
		n *= -1;
	}
	while (lenght > 0)
	{
		ret[index++] = (n / (ft_10base(lenght - 1))) + '0';
		n %= ft_10base(lenght - 1);
		lenght--;
	}
	ret[index] = '\0';
	return (ret);
}
/*
#include <stdio.h>
int	main(void)
{
	int	a = -456;
	printf("org value is :'-456', my value is :'%s'", ft_itoa(a));
}
*/
