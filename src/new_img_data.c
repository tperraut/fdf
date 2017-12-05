/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 16:34:03 by tperraut          #+#    #+#             */
/*   Updated: 2016/06/03 16:51:56 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#include <stdlib.h>

t_img	*new_img_data(void *p_img)
{
	t_img	*i;

	IF_ERROR(!(i = (t_img *)malloc(sizeof(t_img))), "new_img_data() fail");
	i->data = mlx_get_data_addr(p_img, &i->bpp, &i->sizeline, &i->endian);
	return (i);
}
