/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:52:51 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/03 12:16:59 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** function tests for any printing character, including space (` '
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
