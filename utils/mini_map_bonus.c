/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:25:30 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/20 19:14:06 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_size(t_cub *var)
{
	int	size;

	size = var->lines;
	if (size > 15)
		var->pix = 2;
	else
		var->pix = 4;
}

void	back_ground(t_cub *var)
{
	int	i;
	int	j;

	if (var->map_t[var->y][var->x] == '0')
	{
		i = 0;
		while (++i <= var->pix)
		{
			j = 0;
			while (++j <= var->pix)
				var->buf[(var->y * var->pix) + j][(var->x * var->pix)
					+ i] = 0xffffff;
		}
	}
}

void	draw_outline(t_cub *var)
{
	int	i;
	int	j;

	if (var->map_t[var->y][var->x] == '1')
	{
		i = 0;
		while (++i <= var->pix)
		{
			j = 0;
			while (++j <= var->pix)
				var->buf[(var->y * var->pix) + j][(var->x * var->pix)
					+ i] = 0x003300;
		}
	}
}

void	ft_draw_player(t_cub *var, int px, int py)
{
	int	i;
	int	j;

	i = 1;
	while (++i < 5)
	{
		j = 1;
		while (++j < 5)
			mlx_pixel_put(var->mlx, var->mlx_win, (py * var->pix) + j, (px \
						* var->pix) + i, 0xff3414);
	}
}

void	ft_draw_mini_map(t_cub *var)
{
	var->y = 0;
	var->pix = 0;
	get_size(var);
	while (var->map_t[var->y])
	{
		var->x = 0;
		while (var->map_t[var->y][var->x])
		{
			draw_outline(var);
			back_ground(var);
			var->x++;
		}
		var->y++;
	}
}
