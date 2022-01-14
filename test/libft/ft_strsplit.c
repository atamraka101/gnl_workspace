/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:36:24 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/12 21:05:45 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself)
** obtained by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
** Example: ft_strsplit("*hello*fellow***students*", ’*’) returns
** the array ["hello", "fellow", "students"].
** Param. #1 The string to split.
** Param. #2 The delimiter character.
** Return value The array of “fresh” strings result of the split.
*/

#include "libft.h"

static int	n_words(char const *s, char c)
{
	int	i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n_words++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (n_words);
}

static	void	free_list_items(char **res, int ndx)
{
	int	i;

	i = ndx;
	while (i >= 0)
	{
		if (res[i])
			free(res[i]);
		i--;
	}
	free(res);
	res = NULL;
}

static	void	fill_words(char **list, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			list[k] = ft_strndup(&s[j], i - j);
			if (!list[k])
			{
				free_list_items(list, k);
				return ;
			}
			k++;
		}
	}
	list[k] = NULL;
}

char	**ft_strsplit(char const *s, char c)
{
	int		w_count;
	char	**res;

	if (s == NULL || c == '\0')
	{
		res = (char **)malloc(sizeof(char *));
		if (!res)
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	w_count = n_words(s, c);
	res = (char **)malloc(sizeof(char *) * w_count + 1);
	if (!res)
		return (NULL);
	fill_words(res, s, c);
	return (res);
}
