/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 19:02:47 by tperraut          #+#    #+#             */
/*   Updated: 2016/09/13 00:30:32 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft.h"

static int		*tabmap(char **t, int size, int (*f)(const char *s))
{
	int		*tab;
	int		i;

	IF_ERROR(!t || !f || !(tab = (int *)malloc(sizeof(int) * size)),
			"tabmap() fail");
	i = 0;
	while (i < size)
	{
		tab[size - 1 - i] = (*f)(t[i]);
		i++;
	}
	return (tab);
}

static void		set_list(t_list **alst, char **split, int size, int co)
{
	t_list	*tmp;
	int		*tab;

	tab = tabmap(split, size, &ft_atoi);
	tmp = ft_lstnew((void const *)tab, sizeof(int) * size);
	free(tab);
	IF_ERROR(!tmp, "set_list() fail");
	IF_ERROR(co != size, "map error");
	ft_lstadd(alst, tmp);
}

static int		**list_to_tab(t_list **alst, int size)
{
	int		**tab;
	t_list	*tmp;
	int		i;

	tab = (int **)malloc(sizeof(int *) * size);
	IF_ERROR(!tab, "list_to_tab() fail");
	tmp = *alst;
	i = -1;
	while (tmp)
	{
		tab[++i] = (int *)tmp->content;
		tmp = tmp->next;
	}
	ft_lstdel(alst, NULL);
	return (tab);
}

static void		free_null(char **line)
{
	free(*line);
	*line = NULL;
}

t_map			*parser(int fd)
{
	int		rd;
	char	*line;
	t_list	*tmp;
	t_map	*map;
	char	**split;

	line = NULL;
	tmp = NULL;
	IF_ERROR((rd = get_next_line(fd, &line)) < 1, "parser() error");
	IF_ERROR(!(split = ft_strsplit(line, ' ')), "ft_strsplit() fail");
	free_null(&line);
	init_map(&map, ft_tablen(split));
	set_list(&tmp, split, ft_tablen(split), map->co);
	ft_delsplit(&split);
	while ((rd = get_next_line(fd, &line)) > 0)
	{
		IF_ERROR(!(split = ft_strsplit(line, ' ')), "ft_strsplit() fail");
		free_null(&line);
		set_list(&tmp, split, ft_tablen(split), map->co);
		ft_delsplit(&split);
		map->li++;
	}
	IF_ERROR(rd < 0, "get_next_line() fail");
	map->tab = list_to_tab(&tmp, map->li);
	return (map);
}
