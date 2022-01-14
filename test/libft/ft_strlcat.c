/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:26:41 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/07 12:13:18 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** size-bounded string concatenation
** strlcat() take the full size of the destination buffer and
** guarantee NUL-termination if there is room.
** Note that room for the NULL should be included in dstsize.
** returns the initial length of dst plus the length of src
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	d_len;
	size_t	size;
	size_t	index;

	s_len = 0;
	d_len = 0;
	index = 0;
	while (dst[d_len])
		d_len++;
	while (src[s_len])
		s_len++;
	if (dstsize > d_len)
		size = d_len + s_len;
	else
		size = dstsize + s_len;
	while (src[index] && (d_len + 1) < dstsize)
		dst[d_len++] = src[index++];
	dst[d_len] = '\0';
	return (size);
}
