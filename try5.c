
void ft_update_saved(char **saved, char *temp)
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

int	get_next_line(const int fd, char **line)
{
	char temp[BUFF_SIZE + 1];
	int result;
	static char *saved;

	if (fd < 0 || !line)
		return (-1);
	temp[BUFF_SIZE] = '\0';
	result = 1;
	while (result)
	{
		result = read(fd, temp, BUFF_SIZE);
		ft_update_saved(&saved, temp);
		if (ft_strchr(saved, '\n'))
		{
			ft_splitter(line, &saved);
			break;
		}
	}
	return (result);
}

