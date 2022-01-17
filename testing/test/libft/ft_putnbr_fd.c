/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:33:09 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/01 17:33:13 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the integer n to the standard output.
** Param. #1 The integer to output.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	int				sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	nbr = n * sign;
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
	{
		ft_putchar_fd(nbr + '0', fd);
	}
}
