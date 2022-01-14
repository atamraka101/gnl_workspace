/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:46:04 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/24 15:59:43 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the
** successive applications of f. If the allocation fails, the
** function returns NULL.
** Param. #1 A pointer’s to the first link of a list.
** #2 The address of a function to apply to each link of a list.
** Return value The new list.
** Libc functions malloc(3), free(3).
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (lst && f)
	{
		new = f(lst);
		if (!new)
			return (NULL);
		head = new;
		lst = lst->next;
		while (lst)
		{
			new->next = f(lst);
			if (new->next == NULL)
			{
				new->next = NULL;
				ft_lstdel(&head, &ft_lst_delcontent);
				return (NULL);
			}
			new = new->next;
			lst = lst->next;
		}
		return (head);
	}
	return (NULL);
}
