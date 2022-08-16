/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:59:50 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/07/03 17:35:55 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr(int sig)
{
	static char	str;
	static int	get_byte;

	if (sig == SIGUSR1)
		str = 1;
	if (++get_byte == 8)
	{
		get_byte = 0;
		if (!str)
			ft_putchar('\n');
		ft_putchar(str);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	ft_printstr("işlem kimligi --> ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	while (1)
	{
		pause();
	} 
	return (0);
}
