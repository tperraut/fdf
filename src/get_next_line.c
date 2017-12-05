/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 15:19:13 by tperraut          #+#    #+#             */
/*   Updated: 2015/05/27 10:37:20 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>
#include "libft.h"
#include "get_next_line.h"

int		get_end(char **line, char **myline, char **temp)
{
	if (!(*line = ft_strdup(*myline)))
		return (-1);
	free(*myline);
	*myline = *temp;
	return (1);
}

char	*ft_join_free(char **tofree, char *tojoin)
{
	char	*dst;

	if (!(dst = ft_strjoin(*tofree, tojoin)))
		return (NULL);
	if (tofree)
		free(*tofree);
	return (dst);
}

int		ft_check_eof(char **line, char **myline)
{
	if (!line)
		return (-1);
	if (*myline)
	{
		if (*myline[0] == '\0')
			return (0);
		*line = ft_strdup(*myline);
		free(*myline);
		*myline = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char		buf[CHECK(BUFF_SIZE) + 1];
	static char	*myline = NULL;
	int			rd;
	int			len;
	char		*temp;

	rd = 0;
	len = 0;
	while (ft_strchr(myline + (len - rd), '\n') == NULL)
	{
		if (!(rd = read(fd, buf, CHECK(BUFF_SIZE))))
			return (ft_check_eof(line, &myline));
		if (rd == -1 || !line)
			return (-1);
		len += rd;
		buf[rd] = '\0';
		if (!(myline = ft_join_free(&myline, buf)))
			return (-1);
	}
	if (!(temp = ft_strdup(ft_strchr(myline, '\n') + 1)))
		return (-1);
	myline[(size_t)(ft_strchr(myline, '\n') - myline)] = '\0';
	return (get_end(line, &myline, &temp));
}
