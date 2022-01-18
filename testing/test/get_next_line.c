/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:57:02 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/17 22:17:47 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int extract_line_from_buffer(char **line_buff, char **line)
{
	int i;
	int buff_len;
	char *temp;

	buff_len = ft_strlen(*line_buff);
	i = 0;
	while ((*line_buff)[i] && (*line_buff)[i] != '\n')
		i++;
	if (buff_len == i)
		return (0);
	*line = ft_strsub(*line_buff, 0, i);
	if (buff_len - i > 0)
	{
		temp = ft_strsub(*line_buff, i + 1, buff_len - i);
		ft_strdel(line_buff);
		*line_buff = ft_strdup(temp);
		if (temp)
			free(temp);
	}
	return (1);
}

void ft_update_line_buff(char **line_buff, char *data)
{
	char *temp;

	if (!(*line_buff))
		*line_buff = ft_strdup(data);
	else
	{
		temp = ft_strjoin(*line_buff, data);
		free(*line_buff);
		*line_buff = temp;
	}
}

int read_line(int fd, char **line_buff, char **line)
{
	int ret;
	char data[BUFF_SIZE + 1];

	while ((ret = read(fd, data, BUFF_SIZE)) > 0)
	{
		data[ret] = '\0';
		ft_update_line_buff(&line_buff[fd], data);
		if (extract_line_from_buffer(&line_buff[fd], line))
			return (1);
	}
	if (ret == 0 && line_buff[fd] && (ft_strlen(line_buff[fd]) > 0))
	{
		*line = ft_strdup(line_buff[fd]);
		ft_strdel(&line_buff[fd]);
		return (1);
	}
	ft_strdel(&line_buff[fd]);
	return (ret);
}
int get_next_line(const int fd, char **line)
{
	int ret;
	static char	*fd_line_buf[FD_MAX];

	if (fd < 0 || !line || fd >= FD_MAX || BUFF_SIZE < 1)
		return (-1);
	if (fd_line_buf[fd] != NULL)
	{
		if ((ret = extract_line_from_buffer(&fd_line_buf[fd], line)) == 1)
			return (1);
	}
	return (read_line(fd, fd_line_buf, line));
}
