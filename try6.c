#include "get_next_line.h"
#include <stdio.h>

void ft_update_line_buff(char **saved, char *temp)
{
	char *temp2;

	if (!*saved)
		*saved = ft_strdup(temp);
	else
	{
		temp2 = ft_strjoin(*saved, temp);
		free(*saved);
		*saved = temp2;
	}
}

void ft_split_lines(char **line, char **saved)
{
	char **splitted;

	splitted = ft_strsplit(*saved, '\n');
	free(*saved);
/*	if (splitted[0])
		printf("splitted[0]: %s\n", splitted[0]);
	if (splitted[1])
		printf("splitted[1]: %s\n", splitted[1]);*/
	if (splitted[0])
	{
		*line = ft_strdup(splitted[0]);
		free(splitted[0]);
	}
	if (splitted[1])
	{

		*saved = ft_strdup(splitted[1]);
		free(splitted[1]);
	}
	if (splitted)
		free(splitted);
}

int	get_next_line(const int fd, char **line)
{
	char temp[BUFF_SIZE + 1];
	int result;
	static char *saved;

	if (fd < 0 || !line)
		return (-1);
	//temp[BUFF_SIZE] = '\0';
	result = 1;
	while (result)
	{
		ft_memset(temp, '\0', BUFF_SIZE + 1);//
		result = read(fd, temp, BUFF_SIZE);
		if (result == 0)
		{
			/*printf("temp: %s\n", temp);
			printf("saved: %s\n", saved);*/
			*line = NULL;
			break;
		}
		ft_update_line_buff(&saved, temp);
		if (ft_strchr(saved, '\n'))
		{
			ft_split_lines(line, &saved);
			break;
		}
	}
	return (result);
}

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
	return (1);
}
