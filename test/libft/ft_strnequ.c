/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:02:55 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 20:27:33 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description Lexicographical comparison between s1 and s2
** up to n characters or until a ’\0’ is reached.
** If the 2 strings are identical,
** the function returns 1, or 0 otherwise.
** Param. #1 The first string to be compared.
** Param. #2 The second string to be compared.
** Param. #3 The maximum number of characters to be compared.
** Return value 1 or 0 according to if the 2 strings are
** identical or not.
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
