void	ft_splitter(char **line, static char *saved)//changes done in try3 and try4
{
	char *temp;
	char *copy1;
	char *copy2;
	int i;
	int j;

	i = 0;
	temp = ft_strchr(saved, '\n');
	while(saved != temp)
	{
		i++;
		saved++;
	}
	copy1 = (char *)malloc(sizeof(char) * i + 1);
	if (!copy1)
		return ;
	copy1[i] = '\0';
	copy1 = ft_strncpy(copy1, saved, i - 1);
	j = ft_strlen(saved) - i - 1; //for reducing '\n' part address
	copy2 = (char *)malloc(sizeof(char) * j + 1);
	if (!copy2)
		return ;
	//copy2 = ft_strcpy(copy2, &saved[j]);
	copy2 = ft_strcpy(copy2, temp + 1, j);
	*line = ft_strdup(copy1);
	free(saved);
	saved = ft_strdup(copy2);
	free(copy1);
	free(copy2);
	copy1 = NULL;
	copy2 = NULL;
}

/*j = ft_strlen(saved) - i - 1; // for reducing '\n' part address
copy2 = (char *)malloc(sizeof(char) * j + 1);
	if (!copy2)
		return ;*/
