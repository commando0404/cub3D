/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:22:28 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 10:17:21 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw(t_cub *var)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT_)
	{
		x = -1;
		while (++x < WIDTH_)
			var->img.data[y * WIDTH_ + x] = var->buf[y][x];
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img.img, 0, 0);
}
