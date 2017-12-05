/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:44:54 by tperraut          #+#    #+#             */
/*   Updated: 2016/10/02 14:56:32 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	fill_pt(t_pt p, t_img *img)
{
	unsigned char	*pixel;

	if (p.x < 0 || p.y < 0 || p.x > W_IMG || p.y > H_IMG)
		return ;
	pixel = (unsigned char *)img->data + (p.y * img->sizeline
			+ (img->bpp / 8) * p.x);
	pixel[2] = (((W_IMG - p.x) % (2 * W_IMG)) / (W_IMG / 100)) * (255 / 100);
	pixel[1] = ((p.y % (2 * H_IMG)) / (H_IMG / 100)) * (255 / 100);
	pixel[0] = (((2 * W_IMG + p.x) % W_IMG) / (W_IMG / 100)) * (255 / 100);
}

static void	cas1(t_pt p, int dx, int dy, t_img *img)
{
	int		xinc;
	int		yinc;
	int		acc;
	int		i;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = ABS(dx);
	dy = ABS(dy);
	acc = dx / 2;
	i = 1;
	while (i <= dx)
	{
		p.x += xinc;
		acc += dy;
		if (acc >= dx)
		{
			acc -= dx;
			p.y += yinc;
		}
		fill_pt(p, img);
		i++;
	}
}

static void	cas2(t_pt p, int dx, int dy, t_img *img)
{
	int		xinc;
	int		yinc;
	int		acc;
	int		i;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = ABS(dx);
	dy = ABS(dy);
	acc = dy / 2;
	i = 1;
	while (i <= dy)
	{
		p.y += yinc;
		acc += dx;
		if (acc >= dy)
		{
			acc -= dy;
			p.x += xinc;
		}
		fill_pt(p, img);
		i++;
	}
}

void		fill_line(t_pt p1, t_pt p2, t_img *img)
{
	t_pt	p;
	int		dx;
	int		dy;

	pt_new(&p, p1.x, p1.y, p1.z);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	fill_pt(p, img);
	if (ABS(dx) > ABS(dy))
		cas1(p, dx, dy, img);
	else
		cas2(p, dx, dy, img);
}
