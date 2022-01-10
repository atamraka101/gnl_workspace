# include <stdio.h>
# include "try.h"
# include "libft/libft.h"

//inner function has to be static, if possible use static variables atleast once

int	get_next_line(const int fd, char **line)
{
	static char *join;
	char *temp;
	char *newline_checker;

	temp = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (!(temp))
		return (0);
	read(fd, temp, BUFF_SIZE);

	join = temp;
	*line = join;
	newline_checker = ft_strrchr(temp, '\n');
	while (newline_checker == (char *)NULL)
	{
		printf("Entered 1\n");
		read(fd, temp, BUFF_SIZE);
		printf("Entered 2\n");
		join = ft_strjoin(join, temp);
		newline_checker = ft_strrchr(temp, '\n');
	}
	*line = ft_strjoin(*line, join);

	free(temp);
	temp = NULL;
	return (1);
}

int main(int argc, char *argv[])
{
	int fd;
	char **line;

	fd = open("text1.txt", O_RDONLY, 0644);
	if (fd == -1)
		printf("Error\n");
	else
	{
		printf("FD: %d\n",);
		line = (char **)malloc(sizeof(char **));//1 double pointer
		if (!line)
			return (0);
		while (get_next_line(fd, line))
			printf("%s\n", *line);
	}
	close(fd);
	if (line && *line)
	{
		free(*line);
		*line = NULL;
		free(line);
		line = NULL;

	}
	system("leaks a.out");
	return (1);
}


/*int	get_next_line(const int fd, char **line)
{
	char	*start;
	char	*end_of_line;
	start = *line;
	printf("%p\n", *line);
	read(fd, line, BUFF_SIZE);
	end_of_line = *line;
	printf("%p", line);
	write(1, line, BUFF_SIZE);
	write(1, "\n", 1);
	printf("%s\n", line);
	printf("%s\n", start);
	printf("%s\n", end_of_line);
	return 1;
}*/

/*int	get_next_line(const int fd, char **line)
{
	char *saved;
	//static ssize_t location;
	char *checker;

	*line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (!*line) //more error checking required
		return (NULL);
	read(fd, *line, BUFF_SIZE);
	saved = *line;
	checker = ft_strrchr(*line, '\n');
	if (checker != 0)
	{
		get_next_line(fd, line);
		//ft_strjoin(saved, *line);
	}
	write(1, *line, BUFF_SIZE);
	free(*line);
	*line = NULL;
}*/
