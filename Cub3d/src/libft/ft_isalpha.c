/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:25 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:26 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("'a' (true): %s",ft_isalpha('a') == 1 ? "true" : "False");
}
*/
