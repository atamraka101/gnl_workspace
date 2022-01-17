/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:26:39 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/12 11:18:17 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** concatenate strings
** append a copy of the null-terminated string s2 to the end of the
** null-terminated string s1, then add a terminating `\0'
** returns pointer s1
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
