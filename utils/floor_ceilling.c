/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:08:54 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/19 12:38:54 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	floor_and_ceilling(t_cub *var, int y)
{
	int	x;

	x = -1;
	while (++x < WIDTH_)
	{
		var->ray.color = rgb_to_hex(var->text.frgb.r, var->text.frgb.g,
				var->text.frgb.b);
		var->buf[y][x] = var->ray.color;
		var->ray.color = rgb_to_hex(var->text.crgb.r, var->text.crgb.g,
				var->text.crgb.b);
		var->buf[HEIGHT_ - y - 1][x] = var->ray.color;
	}
}
