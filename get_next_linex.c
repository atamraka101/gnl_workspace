/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:57:02 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/16 17:01:58 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_splitter(char **line, char **saved)
{
	char	*copy;
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = *saved;
	while (str[i] != '\n')
		i++;
	*line = ft_strsub(*saved, 0, i);
	len = ft_strlen(*saved) - i;
	copy = ft_strsub(*saved, i + 1, len);
	free(*saved);
	*saved = ft_strdup(copy);
	if (copy)
		free(copy);
}

void	ft_update_line_buff(char **line_buf, char *data)
{
	char	*temp;

	if (!*line_buf)
		*line_buf = ft_strdup(data);
	else
	{
		temp = ft_strjoin(*line_buf, data);
		free(*line_buf);
		*line_buf = temp;
	}
}

void	ft_split_lines(char **line, char **line_buf)
{
	char	**splitted;

	splitted = ft_strsplit(*line_buf, '\n');
	free(*line_buf);
	if (splitted[0])
	{
		*line = ft_strdup(splitted[0]);
		free(splitted[0]);
	}
	if (splitted[1])
	{
		*line_buf = ft_strdup(splitted[1]);
		free(splitted[1]);
	}
	if (splitted)
	{
		free(splitted);
	}
}

int	get_next_line(const int fd, char **line)
{
	char		data[BUFF_SIZE + 1];
	int			result;
	static char	*fd_line_buf[FD_MAX];

	if (fd < 0 || !line || fd > FD_MAX || BUFF_SIZE < 1)
		return (-1);
	result = 1;
	*line = NULL;
	while (result)
	{
		if (fd_line_buf[fd] && ft_strchr(fd_line_buf[fd], '\n'))
		{
			ft_splitter(line, &fd_line_buf[fd]);
			break ;
		}
		else
		{
			ft_memset(data, '\0', BUFF_SIZE + 1);
			result = read(fd, data, BUFF_SIZE);
			ft_update_line_buff(&fd_line_buf[fd], data);
		}
	}
	if (result)
		return (1);
	return (0);
}
