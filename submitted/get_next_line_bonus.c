/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 03:34:01 by dlu               #+#    #+#             */
/*   Updated: 2023/05/09 19:07:14 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static int	prev_init(char **prev)
{
	*prev = (char *) malloc(sizeof(char));
	if (!*prev)
		return (0);
	(*prev)[0] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*prev[FD_MAX];
	ssize_t		read_bytes;
	char		buffer[BUFFER_SIZE];

	if (fd < 0 || (!prev[fd] && !prev_init(&prev[fd])))
		return (NULL);
	while (nl_index(prev[fd], 0) < 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(prev[fd]);
			prev[fd] = NULL;
			return (NULL);
		}
		append_buffer(&prev[fd], buffer, read_bytes);
		if (read_bytes < BUFFER_SIZE)
			return (process_next_line(&prev[fd], nl_index(prev[fd], 1), 1));
	}
	return (process_next_line(&prev[fd], nl_index(prev[fd], 0), 0));
}
/*
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	char	*line;
	int	fd = open("test.md", O_RDONLY);

	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/