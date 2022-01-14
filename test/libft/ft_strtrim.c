/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:43:02 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 20:34:13 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or at
** the end of the string. Will be considered as whitespaces the
** following characters ’ ’, ’\n’ and ’\t’. If s has no
** whitespaces at the beginning or at the end, the function
** returns a copy of s.
** If the allocation fails the function returns NULL.
** Param. #1 The string to be trimed.
** Return value The “fresh” trimmed string or a copy of s.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	front;
	unsigned int	back;

	front = 0;
	if (!s)
		return (NULL);
	while (s[front] == ' ' || s[front] == '\n' || s[front] == '\t')
		front++;
	if (s[front] == '\0')
		return (ft_strnew(0));
	back = front;
	while (s[back] != '\0')
		back++;
	back--;
	while (s[back] == ' ' || s[back] == '\n' || s[back] == '\t')
		back--;
	return (ft_strsub(s, front, back - front + 1));
}
