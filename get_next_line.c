/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:34:31 by pabad-ap          #+#    #+#             */
/*   Updated: 2023/12/02 15:22:27 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_read_fd_buff(int fd, char **tmp)
{
	char	*buff;
	int		i;

	i = 0;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (buff == NULL)
		return ;
	else
	{
		while (i <= BUFFER_SIZE)
		{
			buff[i] = '\0';
			i ++;
		}
	}
	if (read(fd, buff, BUFFER_SIZE) <= 0)
	{
		*tmp = NULL;
		free(buff);
		return ;
	}
	*tmp = ft_strdup(buff);
	free (buff);
}

static void	ft_write_line(char **tmp, char **line, int fd)
{
	char	*p;
	char	*sub;

	p = ft_strchr(*tmp, '\n');
	if (p == NULL)
	{
		*line = ft_strjoin(*line, *tmp);
		ft_read_fd_buff(fd, (char **)tmp);
		if (*tmp == NULL)
			free(*tmp);
		else
			ft_write_line(tmp, line, fd);
	}
	else
	{
		sub = ft_substr(*tmp, 0, (p + 1) - *tmp);
		*line = ft_strjoin(*line, sub);
		p = ft_strdup(p + 1);
		free(*tmp);
		if (!p)
			return ;
		*tmp = p;
	}
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (free(tmp), tmp = NULL, NULL);
	if (tmp)
		ft_write_line(&tmp, &line, fd);
	else
	{
		ft_read_fd_buff(fd, &tmp);
		if (!tmp)
			return (NULL);
		ft_write_line(&tmp, &line, fd);
	}
	if (line[0] == '\0')
	{
		free (line);
		line = NULL;
	}
	return (line);
}
