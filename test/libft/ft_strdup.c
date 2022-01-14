/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:39:33 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 14:59:35 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** save a copy of a string
** allocates sufficient memory for a copy of the string s1, does the copy,
** and returns a pointer to it
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy || s1 == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
