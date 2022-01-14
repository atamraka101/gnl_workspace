/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:48:30 by atamraka          #+#    #+#             */
/*   Updated: 2021/11/24 15:24:15 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** compare byte string
** compares byte string s1 against byte string s2
** Both strings are assumed to be n bytes long.
** returns zero if the two strings are identical,
** otherwise returns the diffference between the first two differing bytes
** Zero-length strings are always identical
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*second;

	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	return (0);
}
