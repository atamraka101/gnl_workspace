#include "get_next_line.h"
#include <stdio.h>

int	get_next_linex(const int fd, char **line)
{
	char	*temp;
	int	result;
	static char	*saved;
	char **spliter;
	int i;

	i = 0;
	saved = NULL;
	temp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!temp)
		return (0);
	result = 1;
	while (result)
	{
		result = read(fd, temp, BUFF_SIZE);
		temp[BUFF_SIZE] = '\0';
		printf("Read: %s\n", temp);
		if (ft_strchr(temp, '\n'))
		{
			spliter = ft_strsplit(temp, '\n');
		}
		if (!saved)
		{
			saved = ft_strdup(temp);
			printf("If saved: %s", saved);
		}
		else if (*spliter)
			{
				while(spliter[i])
				{
					ft_strjoin(saved, spliter[i]);
					i++;
				}
				i = 0;
				printf("Else if saved: %s", saved);
			}
		else
			ft_strjoin(saved, temp);
			printf("Else saved: %s", saved);
	}
	*line = ft_strdup(saved);
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	return (1);
}

/*static void free_spliters_array(char **array, int no_of_list)
{
	int i;

	i = 0;
	while (i < no_of_list)
	{
		free(array[i]);
		i++;
	}
	free(array);
}*/

void	ft_splitter(char **line, char **saved)
{
	char *copy1;
	char *copy2;
	int i;
	int j;

	i = 0;
	copy1 = ft_strchr(*saved, '\n');
	while((*saved)++ != copy1)
		i++;
	copy1 = (char *)malloc(sizeof(char) * i + 1);
	j = ft_strlen(*saved) - i - 1;
	copy2 = (char *)malloc(sizeof(char) * j + 1);
	if (!copy1 || !copy2)
		return ;
	copy1[i] = '\0';
	copy1 = ft_strncpy(copy1, *saved, i - 1);
	copy2 = ft_strcpy(copy2, &(*saved[j]));
	*line = ft_strdup(copy1);
	free(*saved);
	*saved = ft_strdup(copy2);
	free(copy1);
	free(copy2);
	copy1 = NULL;
	copy2 = NULL;
}

void	ft_split_lines(char **line, char *saved)
{
	char **splited;

	splited = ft_strsplit(saved, '\n');

	printf("splited[0]: %s\n", splited[0]);
	printf("splited[1]: %s\n", splited[1]);

	*line = ft_strdup(splited[0]);
	free(saved);
	saved = ft_strdup(splited[1]);

	free (splited[0]);
	free (splited[1]);
	free(splited);
}

int	get_next_line(const int fd, char **line)
{
	char	temp[BUFF_SIZE + 1];
	char	*temp2;
	int	result;
	static char	*saved;
	char **spliter = NULL;
	int i;

	i = 0;

	temp[BUFF_SIZE] = '\0';
	result = 1;
	while (result)
	{
		//printf("Back\n");
		result = read(fd, temp, BUFF_SIZE);

		printf("Read: %s\n", temp);

		if (!saved)
		{
			printf("If (!saved)\n");
			saved = ft_strdup(temp);
			printf("saved: %s\n", saved);
		}
		else
		{
			printf("Else\n");
			temp2 = ft_strjoin(saved, temp);
			printf("saved: %s\n", temp2);
			free(saved);
			saved = temp2;
		}
		if (ft_strchr(saved, '\n'))
		{
			printf("if (ft_strchr(saved, \'\\n\')\n");
			printf("saved: %s\n", saved);
			ft_split_lines(line, saved);
			/*spliter = ft_strsplit(saved, '\n');

			while(spliter[i])
			{
				printf("while(spliter[%d])\n", i);
				temp2 = ft_strjoin(saved, spliter[i]);
				free(saved);
				saved = temp2;

				printf("saved: %s\n", saved);
				printf("spliter[%d]: %s\n", i, spliter[i]);
				i++;
			}
			*line = ft_strdup(spliter[0]);
			free(saved);
			saved = ft_strdup(spliter[1]);
			free_spliters_array(spliter, 2);*/
			break;
		}
		printf("Result :%d\n", result);
	}
	//*line = ft_strdup(saved);

	return (result);
}

int get_next_line2(const int fd, char **line)
{
	int status = 1;
	char *output;
	char hold[BUFF_SIZE + 1];

	hold[BUFF_SIZE] = '\0';

	while(status)
	{
		status = read(fd, hold, BUFF_SIZE);

	}
	printf("%s\n", output);
	return 0;
}

int	main(void)//arg
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
			return (0);
		/*printf("FD : %d \n", fd);
		result = get_next_line(fd, line);
		if (result == 1)
			printf("1 line: %s\n", *line);
		free(*line);
		result = get_next_line(fd, line );
		if (result == 1)
			printf("2 line: %s\n", *line);*/

		while(get_next_line(fd, line))
		{
			printf("Line %d: %s\n", i, *line);
			i++;
			free(*line);
		}
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
