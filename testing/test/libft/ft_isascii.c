/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:20:08 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/17 21:27:32 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** tests for an ASCII character,
** which is any character between 0 and octal 0177(127 dec) inclusive.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
