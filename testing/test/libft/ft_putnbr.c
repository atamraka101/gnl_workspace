/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:20:31 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/01 17:27:40 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the integer n to the standard output.
** Param. #1 The integer to output.
*/

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nbr;
	int				sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	nbr = n * sign;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}
