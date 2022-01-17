/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:12:24 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/28 17:24:25 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates memory using malloc
** returns the allocated needed memory
** The memory allocated is initialized to 0.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	new = (void *)malloc(size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
