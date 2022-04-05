/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:34:47 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/02/02 15:46:16 by ekaraogl         ###   ########.TR       */
/*                                                                            */
/* ************************************************************************** */

//Fonksiyona geçirilen c parametre değerinin alfabede bulunan 
//bir arf ve bir rakam olup olmadığını kontrol eder.
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
