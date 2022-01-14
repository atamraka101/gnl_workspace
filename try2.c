#include "get_next_line.h"
#include <stdio.h>
int	get_next_line2(const int fd, char **line)
{
	static char *saved;
	int result;
	char *temp;

	saved = NULL;
	temp = (char *)malloc(sizeof(char) * BUFF_SIZE);
	//result = read(fd, temp[i], BUFF_SIZE);
	ft_strcat(saved, temp);
	printf("%s\n", saved);
	while (result)
	{
		result = read(fd, temp, BUFF_SIZE);
		ft_strjoin (saved, temp);
		printf("%s\n", saved);
	}
	ft_strcat(*line, saved);
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	return 0;
}



int	main(void)//arg
{
	int fd;
	char **line;
	int result;

	fd = open("text1.txt", O_RDONLY, 0644);
	if (fd < 0)
		printf("Error\n");
	else
	{
		line = (char **)malloc(sizeof(char *));
		if (!line)
			return (0);
		printf("FD : %d \n", fd);
		result = get_next_line(fd, line);
		if (result)
			printf("1 line: %s\n", *line);
		free(*line);
		result = get_next_line(fd, line );
		if (result)
			printf("2 line: %s\n", *line);
	}
	if (line && *line)
	{
		free(*line);
		*line = NULL;
		free(line);
		line = NULL;
	}
	//system ("leaks a.out");
	return (1);
}


/*int get_next_line(const int fd, char **line)
{
	static char *str;
	char *temp;
	char *temp2;
	char **twoLines;

	int result;

	temp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);

	while(1)
	{
		result = read(fd, temp, BUFF_SIZE);
		temp[BUFF_SIZE] = '\0';

		if (!str)
			str = ft_strdup(temp);
		else
		{
			temp2 = ft_strjoin(str, temp);
			free(str);
			str = temp2;
		}
		if(ft_strchr(str, '\n'))
		{
			//printf("Line: %s\n", str);
			//printf("Found\n");
			twoLines = ft_strsplit(str, '\n');
			//printf("First Line: %s\n", twoLines[0]);
			*line = ft_strdup(twoLines[0]);
			//printf("Second Line: %s\n", twoLines[1]);
			free(str);
			str = ft_strdup(twoLines[1]);
			free(twoLines);
			break;
		}

	}
	free(temp);
	return (1);
}
*/
