/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:12:13 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/13 14:14:13 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_splittero(char **line, char **saved)
{
	char *temp;
	char *copy1;
	char *copy2;
	int i;
	int j;

	i = 0;
	//printf("*Saved = %s\n", *saved);
	//printf("*Line = %s\n", *line);
	temp = ft_strchr(*saved, '\n');
	copy1 = *saved;
	while(copy1 != temp)
	{
		i++;
		copy1++;
	}
	//printf("*Saved = %s\n", copy1);
	copy1 = NULL;
	copy1 = (char *)malloc(sizeof(char) * i + 1);
	if (!copy1)
		return ;
	copy1[i] = '\0';
	copy1 = ft_strncpy(copy1, *saved, i - 1);
	j = ft_strlen(*saved) - i - 1; //for reducing '\n' part address
	copy2 = (char *)malloc(sizeof(char) * j + 1);
	if (!copy2)
		return ;
	//copy2 = ft_strcpy(copy2, &saved[j]);
	copy2 = ft_strncpy(copy2, temp + 1, j);
	*line = ft_strdup(copy1);
	free(*saved);
	*saved = ft_strdup(copy2);
	free(copy1);
	free(copy2);
	copy1 = NULL;
	copy2 = NULL;
	//printf("*Saved = %s\n", *saved);
	//printf("*Line = %s\n", *line);
}

static void	ft_splitterm(char **line, char **saved)
{
	char *copy1;
	char *copy2;
	int i;
	int j;

	i = 0;
	//printf("*Saved = %s\n", *saved);
	//printf("*Line = %s\n", *line);
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
	//printf("..........\n");
	//printf("*Saved = %s\n", *saved);
	//printf("*Line = %s\n", *line);
}

int	get_next_line(const int fd, char **line)
{
	char	temp[BUFF_SIZE + 1];
	char	*temp2;
	int	result;
	static char	*saved;
	int i;

	i = 0;

	temp[BUFF_SIZE] = '\0';
	result = 1;
	while (result)
	{
		result = read(fd, temp, BUFF_SIZE);

		//printf("Read: %s\n", temp);

		if (!saved)
		{
			//printf("If (!saved)\n");
			saved = ft_strdup(temp);
			//printf("saved: %s\n", saved);
		}
		else
		{
			//printf("Else\n");
			temp2 = ft_strjoin(saved, temp);
			//printf("saved: %s\n", temp2);
			free(saved);
			saved = temp2;
		}
		if (ft_strchr(saved, '\n'))
		{
			//printf("if (ft_strchr(saved, \'\\n\')\n");
			//printf("saved: %s\n", saved);
			ft_splittero(line, &saved);
			break;
		}
	}
	return (result);
}

/*int	main(void)//arg
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
		printf("FD : %d \n", fd);
		/*result = get_next_line(fd, line);
		if (result)
			printf("1 line: %s\n", *line);

		free(*line);
		result = get_next_line(fd, line );
		if (result == 1)
			printf("2 line: %s\n", *line);*/
/*
		while(get_next_line(fd, line))
		{
			printf("Line %d: %s\n", i, *line);
			printf(".................\n");
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
*/
