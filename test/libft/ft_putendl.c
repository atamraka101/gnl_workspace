/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:54:57 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/16 15:19:34 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s to the standard output followed by a ’\n’.
** Param. #1 The string to output.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s)
		ft_putstr(s);
	ft_putchar('\n');
}
