/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:58:37 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 15:30:45 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** it locates the last occurrence of c
** return a pointer to the located character,
** or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
