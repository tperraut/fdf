/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:11:50 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/25 20:49:08 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#include <stdlib.h>
#include <unistd.h>

int		finish(void *param)
{
	t_env	*e;

	if (param)
	{
		e = (t_env *)param;
		if (e->map)
			free_map(&(e->map));
		if (e->img)
			mlx_destroy_image(e->mlx, e->img);
		if (e->mlx)
			mlx_destroy_window(e->mlx, e->win);
		close(e->op);
	}
	exit(0);
	return (0);
}
