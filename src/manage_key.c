/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 10:42:34 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/25 20:34:03 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"
#include "fdf.h"

#include <stdlib.h>

int	manage_key(int keycode, void *param)
{
	if (param)
	{
		if (keycode == K_ESCAPE)
			finish(param);
	}
	return (0);
}
