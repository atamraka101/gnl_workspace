/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:21:44 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 21:12:53 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy byte string
** function copies len bytes from string src to string dst.
** The two strings may over-lap;
** the copy is always done in a non-destructive manner.
** returns the original value of dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = len;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d <= s)
		return (ft_memcpy(dst, src, len));
	if (d > s)
	{
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (d);
}
