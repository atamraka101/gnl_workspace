/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:48:22 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/23 19:39:55 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates the list lst and applies the function f to each link.
** Param#1 A pointer to the first link of a list.
** P#2 The address of a function to apply to each link of a list.
** Return value None.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst != NULL && f != NULL)
	{
		while (lst)
		{
			(*f)(lst);
			lst = lst->next;
		}
	}
}
