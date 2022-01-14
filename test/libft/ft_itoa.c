/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:18:57 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/01 16:48:31 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** integer to string
** allocate with malloc for the new string ending with '\0'
** negative nos. are supported
** returns string representing the integer passed as argument
*/
#include "libft.h"

static int	length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*fill_string(char *a, int n, int i)
{
	unsigned int	nbr;
	int				sign;

	sign = 1;
	a[i--] = '\0';
	if (n == 0)
	{
		a[0] = '0';
		return (a);
	}
	if (n < 0)
	{
		sign = -1;
		a[0] = '-';
	}
	nbr = n * sign;
	while (nbr > 0)
	{
		a[i--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*a;

	i = length(n);
	a = (char *)malloc((sizeof(char)) * (i + 1));
	if (!a)
		return (NULL);
	fill_string(a, n, i);
	return (a);
}
