/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:59:54 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/07/03 14:50:53 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(int pid, char *a)
{
	int	i;
	int	c;

	while (*a)
	{
		i = 8;
		c = *a++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep (100);
		}
	}
	i = 8;
	while (i--)
	{
		kill (pid, SIGUSR2);
		usleep (50);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printstr ("yanlış girdiniz");
		return (0);
	}
	ft_kill(ft_atoi(av[1]), av[2]);
}
