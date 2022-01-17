/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:09:00 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 17:53:06 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the char c to the file descriptor fd.
** Param. #1 The character to output.
** Param. #2 The file descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
