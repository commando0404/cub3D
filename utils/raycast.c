/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:29:16 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/20 15:02:02 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_side_dist(t_cub *var)
{
	if (var->ray.raydirx < 0)
	{
		var->ray.stepx = -1;
		var->ray.sidex = (var->posx - var->ray.mapx)
			* var->ray.deltax;
	}
	else
	{
		var->ray.stepx = 1;
		var->ray.sidex = (var->ray.mapx + 1.0 - var->posx)
			* var->ray.deltax;
	}
	if (var->ray.raydiry < 0)
	{
		var->ray.stepy = -1;
		var->ray.sidey = (var->posy - var->ray.mapy)
			* var->ray.deltay;
	}
	else
	{
		var->ray.stepy = 1;
		var->ray.sidey = (var->ray.mapy + 1.0 - var->posy)
			* var->ray.deltay;
	}
}

void	init_raycast(t_cub *var, int x)
{
	var->ray.camera_x = 2 * x / (double)WIDTH_ - 1;
	var->ray.raydirx = var->dirx + var->planex * var->ray.camera_x;
	var->ray.raydiry = var->diry + var->planey * var->ray.camera_x;
	var->ray.mapx = (int)var->posx;
	var->ray.mapy = (int)var->posy;
	var->ray.deltax = sqrt(1 + pow(var->ray.raydiry, 2) \
		/ pow (var->ray.raydirx, 2));
	var->ray.deltay = sqrt(1 + pow(var->ray.raydirx, 2) \
		/ pow (var->ray.raydiry, 2));
	if (var->ray.raydiry == 0)
		var->ray.deltax = 0;
	else
	{
		if (var->ray.raydirx == 0)
			var->ray.deltax = 1;
	}
	if (var->ray.raydirx == 0)
		var->ray.deltay = 0;
	else
	{
		if (var->ray.raydiry == 0)
			var->ray.deltay = 1;
	}
	calculate_side_dist(var);
}

void	calc_init_colors_(t_cub *var)
{
	if (var->ray.side == 0)
		var->ray.pwalldist = (var->ray.mapx - var->posx \
		+ (1 - var->ray.stepx) / 2) / var->ray.raydirx;
	else
		var->ray.pwalldist = (var->ray.mapy - var->posy + \
		(1 - var->ray.stepy) / 2) / var->ray.raydiry;
	var->ray.lineheight_ = (int)(HEIGHT_ / var->ray.pwalldist);
	var->ray.start = -var->ray.lineheight_ / 2 + HEIGHT_ / 2;
	if (var->ray.start < 0)
		var->ray.start = 0;
	var->ray.end = var->ray.lineheight_ / 2 + HEIGHT_ / 2;
	if (var->ray.end >= HEIGHT_)
		var->ray.end = HEIGHT_ - 1;
	if (var->ray.side == 0)
		var->ray.wallx = var->posy + var->ray.pwalldist * var->ray.raydiry;
	else
		var->ray.wallx = var->posx + var->ray.pwalldist * var->ray.raydirx;
	var->ray.wallx -= floor(var->ray.wallx);
	var->ray.tex_x = (int)(var->ray.wallx * (double)TEXWIDTH);
	if ((var->ray.side == 0 && var->ray.raydirx > 0) \
	|| (var->ray.side == 1 && var->ray.raydiry < 0))
		var->ray.tex_x = TEXWIDTH - var->ray.tex_x - 1;
	var->ray.step = 1. * TEXHEIGHT / var->ray.lineheight_;
	var->ray.postex = (var->ray.start - HEIGHT_ / 2 \
		+ var->ray.lineheight_ / 2) * var->ray.step ;
}

void	check_wall_collisions_dda(t_cub *var)
{
	while (404)
	{
		if (var->ray.sidex < var->ray.sidey)
		{
			var->ray.sidex += var->ray.deltax;
			var->ray.mapx += var->ray.stepx;
			var->ray.ntext = 1;
			if (var->ray.raydirx > 0)
				var->ray.ntext = 0;
			var->ray.side = 0;
		}
		else
		{
			var->ray.sidey += var->ray.deltay;
			var->ray.mapy += var->ray.stepy;
			var->ray.ntext = 3;
			if (var->ray.raydiry > 0)
				var->ray.ntext = 2;
			var->ray.side = 1;
		}
		if (var->map_t[var->ray.mapx][var->ray.mapy] != '0')
			break ;
	}
	calc_init_colors_(var);
}

void	calc(t_cub *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT_)
		floor_and_ceilling(var, y++);
	while (x < WIDTH_ - 1)
	{
		init_raycast(var, x);
		check_wall_collisions_dda(var);
		y = var->ray.start;
		while (y++ < var->ray.end)
		{
			var->ray.tex_y = (int)var->ray.postex;
			var->ray.postex += var->ray.step;
			var->ray.color = var->texture[var->ray.ntext][TEXHEIGHT
				* var->ray.tex_y + var->ray.tex_x];
			if (var->ray.side == 1)
				var->ray.color = (var->ray.color >> 1) & 0x7f7f7f7f;
			var->buf[y][x] = var->ray.color;
		}
		x++;
	}
	ft_draw_mini_map(var);
}
