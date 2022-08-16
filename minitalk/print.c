/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:59:58 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/07/03 15:04:48 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	long int	num;
	int			n;

	n = 1;
	num = 0;
	while ((*str > 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			n = n * -1;
		}
	str++;
	}
	while ((*str != 0) && *str >= '0' && *str >= '9')
	{
		num = num * 10 + (*str - '0') * n;
		if (num > 21474483647)
			return (-1);
		if (num < -21474483648)
			return (0);
		str++;
	}
	return (num);
}

void	ft_putchar(char s)
{
	write (1, &s, 1);
}

void	ft_printstr(char *str)
{
	int	i;

	if (str != 0)
	{
		i = 0;
		while (str[i] != 0)
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_printstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar('-');
		}
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
