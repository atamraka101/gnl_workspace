/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:01:56 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/01 21:16:08 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locate byte in byte string
** returns a pointer to the byte located, or,
** NULL if no such byte exist within n bytes
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*copy;

	i = 0;
	copy = (unsigned char *)s;
	while (i < n)
	{
		if (copy[i] == (unsigned char)c)
			return (&copy[i]);
		i++;
	}
	return (NULL);
}
