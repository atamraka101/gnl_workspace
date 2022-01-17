#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
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
			//ft_strdel(line);
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
	result = read_line(fd, &fd_line_buf[fd], line);
	return(result);
}


/*
** Invalid file descriptor #2
*/
/*
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	char		*filename;

	filename = "gnl9_2.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		if (close(fd) == 0)
		{
			printf("fd:%d\n", fd);
			line = NULL;
			ret = get_next_line(fd, &line);
			if (ret != -1)
				printf("-> must have returned '-1' when receiving a closed file descriptor\n");
			else
				printf("OK\n");
		}
		else
		{
			printf("An error occured while closing file descriptor associated with file %s\n", filename);
			return (0);
		}
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
*/
int main(void)
{
	int fd1;
	int fd2;
	int fd3;
	char **line;
	int result;
	int i;

	i = 0;
	fd1 = open("text1.txt", O_RDONLY, 0644);
	fd2 = open("text2.txt", O_RDONLY, 0644);
	fd3 = open("text3.txt", O_RDONLY, 0644);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		printf("Error\n");
	else
	{
		line = (char **)malloc(sizeof(char *));
		if (!line)
		{
			printf("Error allocating **line\n");
			return (0);
		}
		printf("FD1 : %d \n", fd1);
		printf("FD2 : %d \n", fd2);
		printf("FD3 : %d \n", fd3);
		result = get_next_line(fd1, line);
		if (result)
			printf("FD1 line: %s\n", *line);
		free(*line);
		result = get_next_line(fd2, line );
		if (result)
			printf("FD2 line: %s\n", *line);
		free(*line);
		result = get_next_line(fd3, line );
		if (result)
			printf("FD3 line: %s\n", *line);
		free(*line);
		result = get_next_line(fd1, line );
		if (result)
			printf("FD1 line 2: %s\n", *line);
		free(*line);
		result = get_next_line(fd2, line );
		if (result)
			printf("FD2 line 2: %s\n", *line);
		free(*line);
		result = 1;
		while (result)
		{
			result = get_next_line(fd3, line);
			if (result == 0)
				printf("XXX\n");
			printf("Line %d: %s\n", i, *line);
			free(*line);
			i++;
		}
		printf("Are you here?\n");
	}
	if (line)
	{
		if (*line)
			free(*line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (1);
}

