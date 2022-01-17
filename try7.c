#include "get_next_line.h"
#include <stdio.h>

void	ft_splitter(char **line, char **saved)
{
	char	*copy;
	int i;
	int len;
	char *str = *saved;
	i = 0;

	while (str[i] != '\n')
		i++;

	/*printf("ft_splitter: i: %d\n", i);
	printf("ft_splitter: saved: %s\n", *saved);
	printf("ft_spliter: saved Len: %d\n", ft_strlen(*saved));*/
	*line = ft_strsub(*saved, 0, i);
	//printf("ft_spliter: line: %s\n", *line);
	len = ft_strlen(*saved) - i;
	//printf("ft_spliter: len: %d\n", len);
	copy = ft_strsub(*saved, i + 1, len);
	free(*saved);
	*saved = ft_strdup(copy);
	if (copy)
		free(copy);
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

void ft_split_lines(char **line, char **line_buf)
{
	char **splitted;

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

int get_next_line(const int fd, char **line)
{
	char data[BUFF_SIZE + 1];
	int result;
	//char *line_buf;
	static char	*fd_line_buf[FD_MAX];

	if (fd < 0 || !line || fd > FD_MAX || BUFF_SIZE < 1)
		return (-1);
	result = 1;
	/*if (fd_line_buf[fd])
		line_buf = ft_strdup(fd_line_buf[fd]);*/
	while (result)
	{
		ft_memset(data, '\0', BUFF_SIZE + 1);
		result = read(fd, data, BUFF_SIZE);
		if (result == 0)
		{
			*line = NULL;
			break;
		}
		ft_update_line_buff(&fd_line_buf[fd], data);
		if (ft_strchr(fd_line_buf[fd], '\n'))
		{
			ft_splitter(line, &fd_line_buf[fd]);
			//ft_split_lines(line, &fd_line_buf[fd]);
			//fd_line_buf[fd] = ft_strdup(line_buf);
			/*free(line_buf);
			line_buf = NULL;*/
			break;
		}
	}
	return (result);
}

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
		//if (result)
			printf("FD1 line: %s\n", *line);
		free(*line);
		result = get_next_line(fd2, line );
		//if (result)
			printf("FD2 line: %s\n", *line);
			free(*line);
		result = get_next_line(fd3, line );
		//if (result)
			printf("FD3 line: %s\n", *line);
		result = get_next_line(fd1, line );
		//if (result)
			printf("FD1 line 2: %s\n", *line);
		result = get_next_line(fd2, line );
		//if (result)
			printf("FD2 line 2: %s\n", *line);
		/*while (get_next_line(fd, line))
		{
			printf("Line %d: %s\n", i, *line);
			free(*line);
			i++;
		}*/
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

/*
int main(void)
{
	int fd;
	char **line;
	int result;
	int i;

	i = 0;
	fd = open("text1.txt", O_RDONLY, 0644);
	if (fd < 0)
		printf("Error\n");
	else
	{
		line = (char **)malloc(sizeof(char *));
		if (!line)
		{
			printf("Error allocating **line\n");
			return (0);
		}

		while (get_next_line(fd, line))
		{
			printf("Line %d: %s\n", i, *line);
			free(*line);
			i++;
		}
	}
	if (line)
	{
		if (*line)
			free(*line);
		free(line);
	}
	close(fd);
	return (1);
}
*/
