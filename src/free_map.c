/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 09:30:59 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/25 20:22:50 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdlib.h>

void	free_map(t_map **map)
{
	t_map	*tmp;
	int		i;

	i = 0;
	if (!map || !*map)
		return ;
	tmp = *map;
	while (i < tmp->li)
	{
		free(tmp->tab[i]);
		i++;
	}
	free(tmp->tab);
	free(tmp);
}
