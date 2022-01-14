/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:18:43 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/17 11:35:08 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copies len characters from src to dst.
** src < len, then remainning dst filled with '\0' characters
** returns dst
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (len != 0)
		{
			dst[i] = src[i];
			len--;
		}
		i++;
	}
	while (len != 0)
	{
		dst[i++] = '\0';
		len--;
	}
	return (dst);
}
