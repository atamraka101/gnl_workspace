/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delcontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:38:52 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/31 15:31:28 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** freeing content of datatypes: int and char only
*/

#include "libft.h"

void	ft_lst_delcontent(void *content, size_t size)
{
	if (!content)
	{
		ft_bzero(content, size);
		free(content);
	}
}
