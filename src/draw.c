/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:45:55 by tperraut          #+#    #+#             */
/*   Updated: 2016/10/02 16:12:48 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_bg(t_img *img)
{
	int				x;
	int				y;
	unsigned char	*pixel;

	y = 0;
	while (y <= H_IMG)
	{
		x = 0;
		while (x <= W_IMG)
		{
			pixel = (unsigned char *)img->data + y * img->sizeline
				+ (img->bpp / 8) * x;
			pixel[2] = (((W_IMG - x) % (2 * W_IMG)) / (W_IMG / 100))
				* (255 / 100);
			pixel[1] = ((y % (2 * H_IMG)) / (H_IMG / 100)) * (255 / 100);
			pixel[0] = (((2 * W_IMG + x) % W_IMG) / (W_IMG / 100))
				* (255 / 100);
			x++;
		}
		y++;
	}
}

/*
** 0 1
** 2
*/

static void	drawing(t_pt *p, int i, int j, t_env *e)
{
	if (j + 1 < (e->map)->co)
	{
		pt_new(&(p[1]), i, j + 1, ((e->map)->tab)[i][j + 1]);
		pt_iso(&(p[1]), (e->map)->bw, (e->map)->cz);
		fill_line(p[0], p[1], e->img_data);
	}
	if (i + 1 < (e->map)->li)
	{
		pt_new(&(p[2]), i + 1, j, ((e->map)->tab)[i + 1][j]);
		pt_iso(&(p[2]), (e->map)->bw, (e->map)->cz);
		fill_line(p[0], p[2], e->img_data);
	}
}

int			draw(void *param)
{
	t_env	*e;
	t_pt	*p;
	int		i;
	int		j;

	e = (t_env *)param;
	p = (t_pt *)malloc(sizeof(t_pt) * 4);
	//print_map(*(e->map));
	pt_new(&(p[0]), 0, 0, ((e->map)->tab)[0][0]);
	pt_iso(&(p[0]), (e->map)->bw, (e->map)->cz);
	i = -1;
	while (++i < (e->map)->li)
	{
		j = -1;
		while (++j < (e->map)->co)
		{
			drawing(p, i, j, e);
			if (j == 0)
				p[3] = p[2];
			p[0] = p[1];
		}
		p[0] = p[3];
	}
	ft_expose(e);
	return (0);
}
