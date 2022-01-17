/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:57:02 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/17 09:21:05 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int extract_line_from_buff(char **buffer, char **line)
{
	int i;
	int buff_len;
	char *str;
	char *temp;

	str = *buffer;
	buff_len = ft_strlen(str);
	i = 0;
	while (i < buff_len && str[i] != '\n')
		i++;
	if (buff_len == i)
		return (0);
	*line = ft_strsub(str, 0, i);
	if (i + 1 < buff_len)
	{
		temp = ft_strsub(str, i + 1, buff_len - i);
		ft_strdel(buffer);
		*buffer = ft_strdup(temp);
		if (temp)
			free(temp);
	}
	else
		ft_strdel(buffer);
	return (1);
}

void ft_update_line_buff(char **line_buf, char *data)
{
	char *temp;

	if (!*line_buf)
		*line_buf = ft_strdup(data);
	else
	{
		temp = ft_strjoin(*line_buf, data);
		free(*line_buf);
		*line_buf = temp;
	}
}

int read_line(int fd, char **line_buffer, char **line)
{
	int read_bytes;
	char data[BUFF_SIZE + 1];

	while (1)
	{
		ft_memset(data, '\0', BUFF_SIZE + 1);
		read_bytes = read(fd, data, BUFF_SIZE);
		if (read_bytes <= 0)
		{
			if (*line_buffer && (ft_strlen(*line_buffer) > 0))
			{
				*line = ft_strdup(*line_buffer);
				ft_strdel(line_buffer);
				return (1);
			}
			ft_strdel(line);
			return (read_bytes);
		}
		ft_update_line_buff(line_buffer, data);
		if (ft_strchr(*line_buffer, '\n'))
		{
			extract_line_from_buff(line_buffer, line);
			return (1);
		}
	}
}

int get_next_line(const int fd, char **line)
{
	int result;
	static char	*fd_line_buf[FD_MAX];

	if (fd < 0 || !line || fd >= FD_MAX || BUFF_SIZE < 1)
		return (-1);

	if (fd_line_buf[fd])
	{
		result = extract_line_from_buff(&fd_line_buf[fd], line);
		if (result)
			return (1);
	}
	return(read_line(fd, &fd_line_buf[fd], line));
}
