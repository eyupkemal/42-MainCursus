/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:47 by tacikgoz          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:48 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
/*
#include <stdio.h>
int	main(void)
{
	printf("'a' (false): %s",ft_isalnum('a') == 1 ? "true" : "False");
}
*/
