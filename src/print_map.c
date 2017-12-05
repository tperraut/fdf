/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 02:24:16 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/24 07:19:52 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	print_map(t_map m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m.li)
	{
		j = -1;
		while (++j < m.co)
		{
			ft_putnbr(m.tab[i][j]);
			ft_putstr(" ");
		}
		ft_putendl("");
	}
}
