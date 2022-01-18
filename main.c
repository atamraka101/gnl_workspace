#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd1;
	int fd2;
	int fd3;
	char **line = NULL;
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
			printf("Line %d: %s\n", i, *line);
			free(*line);
			*line = NULL;
			i++;
		}

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
	system("leaks a.out");
	return (1);
}
