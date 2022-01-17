/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:37:52 by atamraka          #+#    #+#             */
/*   Updated: 2021/12/21 11:07:49 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The
** variables content and content_size of the new link are
** initialized by copy of the parameters of the function.
** If the parameter content is nul, the variable content is
** initialized to NULL and the variable content_size is
** initialized to 0 even if the parameter content_size isn’t.
** The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
** Param. #1 The content to put in the new link.
** Param. #2 The size of the content of the new link.
** Return value The new link.
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = (void *)malloc(content_size);
		if (newlist->content == NULL)
		{
			free(newlist);
			return (NULL);
		}
		ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
