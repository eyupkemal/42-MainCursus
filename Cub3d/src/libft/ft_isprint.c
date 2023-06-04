/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:45 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:46 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("'a' (true): %s",ft_isalnum('a') == 1 ? "true" : "False");
}
*/
