/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:57:02 by atamraka          #+#    #+#             */
/*   Updated: 2022/01/09 13:02:54 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read, malloc and free only
// 5 funs
// static variables are allowed
#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h> //need to remove this

static void	ft_reading(char *filename[])
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY); //0644 or 0 OR chmod at end
	if (fd == -1)
		printf("Error\n");
	else
		printf("Success\n");
	line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);// free necessary
	if (!line)
		return (NULL);
	get_next_line(fd, &line);
	close(fd);
}
int	get_next_line(const int fd, char **line)
{
	read(fd, &line, BUFF_SIZE + 1);
	ft_putstr_fd()

}
int	main(int argc, char *argv[])
{
	/*
	if (argc > 1)
	else file
	*/
	ft_reading("read.txt");
	return (1);
}
