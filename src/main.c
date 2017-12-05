/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 02:28:29 by tperraut          #+#    #+#             */
/*   Updated: 2016/10/02 16:15:07 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

#include <fcntl.h>

int	main(int ac, char **av)
{
	t_env	e;

	IF_ERROR(ac < 2 || ac > 3, "Usage ./fillit file optional_number");
	IF_ERROR((e.op = open(av[1], O_RDONLY)) < 0, "open() fail");
	IF_ERROR(!(e.mlx = mlx_init()), "mlx_init() fail");
	IF_ERROR(!(e.win = mlx_new_window(e.mlx, W_MAX, H_MAX, "FDF")),
			"mlx_new_window() fail");
	e.map = parser(e.op);
	(e.map)->bw = ft_min(W_MAX / (e.map)->co, H_MAX / (e.map)->li);
	(e.map)->cz = (ac > 2) ? ft_max(ABS(ft_atoi(av[2])), 1) : 8;
	IF_ERROR(!(e.img = mlx_new_image(e.mlx, W_IMG, H_IMG)),
			"mlx_new_image() fail");
	e.img_data = new_img_data(e.img);
	mlx_key_hook(e.win, manage_key, &e);
	mlx_mouse_hook(e.win, manage_mouse, &e);
	mlx_expose_hook(e.win, &draw, &e);
	mlx_hook(e.win, CROSS_V, CROSS_MASK, finish, &e);
	mlx_loop(e.mlx);
	return (0);
}
