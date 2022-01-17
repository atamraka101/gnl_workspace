/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:31:10 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/03 12:36:20 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** alphanumeric character test
** tests for any character for which isalpha(3) or isdigit(3) is true
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
