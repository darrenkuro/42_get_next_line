/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 03:34:55 by dlu               #+#    #+#             */
/*   Updated: 2023/05/10 02:05:57 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

# define FD_MAX	4096
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

char	*get_next_line(int fd);

int		ft_strlen(char *s);
int		nl_index(char *prev, int end);
int		append_buffer(char **prev, char *buffer, ssize_t n);
char	*ft_substr(char *s, int start, int len);

#endif
