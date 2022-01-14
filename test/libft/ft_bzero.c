/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:59:22 by atamraka          #+#    #+#             */
/*   Updated: 2021/11/21 22:06:09 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** write zeroes to a byte string
** he bzero() function writes n zeroed bytes to the string s.
** If n is zero, bzero() does nothing.
** it doesn't return anything
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
