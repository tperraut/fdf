/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:01:47 by tperraut          #+#    #+#             */
/*   Updated: 2016/10/02 15:58:53 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <math.h>

void	pt_new(t_pt *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	pt_inv(t_pt *p)
{
	pt_new(p, p->y, p->x, p->z);
}

void	pt_iso(t_pt *p, int bw, int cz)
{
	double	x;
	double	y;
	double	cst;

	cst = (double)cz;
	x = 400 + (p->x - p->y) * ((double)bw / 2);
	y = 400 + (-p->z / cst - 0.5 * (p->x + p->y)) * ((double)bw / 2);
	pt_new(p, (int)nearbyint(x), (int)nearbyint(y), p->z);
}
