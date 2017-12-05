/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 21:28:15 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/30 11:13:04 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	manage_mouse(int button, int x, int y, void *param)
{
	if (param)
		return (button + x + y);
	return (0);
}
