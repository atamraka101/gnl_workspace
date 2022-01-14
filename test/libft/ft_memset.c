/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:26:41 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/01 21:38:58 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** memset - fill byte string with byte value
*/

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*p;

	p = (char *)str;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (str);
}
