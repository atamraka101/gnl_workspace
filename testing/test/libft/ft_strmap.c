/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:57:41 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/11 14:26:33 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3))
** resulting from the successive applications of f.
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s.
** Return value The “fresh” string created from the successive applications of
** f.
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (!s || !f)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = (*f)(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
