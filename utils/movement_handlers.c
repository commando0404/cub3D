/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:43:28 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/16 17:03:42 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_left(t_cub *var, double move_speed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = var->dirx;
	var->dirx = var->dirx * cos(move_speed) - var->diry * sin(move_speed);
	var->diry = olddirx * sin(move_speed) + var->diry * cos(move_speed);
	oldplanex = var->planex;
	var->planex = var->planex * cos(move_speed) - var->planey * sin(move_speed);
	var->planey = oldplanex * sin(move_speed) + var->planey * cos(move_speed);
}

void	move_right(t_cub *var, double move_speed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = var->dirx;
	var->dirx = var->dirx * cos(-move_speed) - var->diry * sin(-move_speed);
	var->diry = olddirx * sin(-move_speed) + var->diry * cos(-move_speed);
	oldplanex = var->planex;
	var->planex = var->planex * cos(-move_speed) - var->planey
		* sin(-move_speed);
	var->planey = oldplanex * sin(-move_speed) + var->planey * cos(-move_speed);
}

void	move_up(t_cub *var)
{
	if (var->map_t[(int)(var->posx + var->dirx
			* var->move_speed)][(int)(var->posy)] == '0')
		var->posx += var->dirx * var->move_speed;
	if (var->map_t[(int)(var->posx)][(int)(var->posy + var->diry
			* var->move_speed)] == '0')
		var->posy += var->diry * var->move_speed;
}

void	move_down(t_cub *var)
{
	if (var->map_t[(int)(var->posx - var->dirx
			* var->move_speed)][(int)(var->posy)] == '0')
		var->posx -= var->dirx * var->move_speed;
	if (var->map_t[(int)(var->posx)][(int)(var->posy - var->diry
			* var->move_speed)] == '0')
		var->posy -= var->diry * var->move_speed;
}
