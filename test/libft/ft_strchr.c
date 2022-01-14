/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:55:13 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 15:20:38 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locate first occurrence of a character c(converted to char) in string s
** '\0' is part of the string
** returns a pointer to the located character or,
** NULL if there is no character in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	len++;
	while (i < len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
