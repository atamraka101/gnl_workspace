/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:39:57 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 22:18:26 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** convert ASCII string to integer
** function converts the initial portion
** of the string pointed to by str to int representation.
** considers space, \t, \r, \n, \f,\v, - and +
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	long			sign;
	long			result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return ((int)result);
}
