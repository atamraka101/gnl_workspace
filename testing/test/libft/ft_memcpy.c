/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:11:24 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 16:27:54 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy memory area
** copies n bytes from memory area src to dst
** overlap behavior undefined
** Applications in which dst and src might overlap should memmove(3) instead.
** returns the original value of dst
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src && n > 0)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
