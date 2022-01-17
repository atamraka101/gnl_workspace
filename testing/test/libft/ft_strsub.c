/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:23:18 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/16 09:44:58 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” substring
** from the string given as argument. The substring begins at
** indexstart and is of size len. If start and len aren’t
** refering to a valid substring, the behavior is undefined.
** If the allocation fails, the function returns NULL.
** Param. #1 The string from which create the substring.
** Param. #2 The start index of the substring.
** Param. #3 The size of the substring.
** Return value The substring.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s || (start > ft_strlen(s)))
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
