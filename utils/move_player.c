/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:22:27 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/17 15:53:48 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move_right_(t_cub *var)
{
	if (var->map_t[(int)(var->posx + var->planex
			* var->move_speed)][(int)(var->posy)] == '0')
		var->posx += var->planex * var->move_speed;
	if (var->map_t[(int)var->posx][(int)(var->posy + var->planey \
			* var->move_speed)] == '0')
		var->posy += var->planey * var->move_speed;
}

static void	move_left_(t_cub *var)
{
	if (var->map_t[(int)(var->posx - var->planex
			* var->move_speed)][(int)(var->posy)] == '0')
		var->posx -= var->planex * var->move_speed;
	if (var->map_t[(int)var->posx][(int)(var->posy - var->planey \
			* var->move_speed)] == '0')
		var->posy -= var->planey * var->move_speed;
}

int	key_update(int key, t_cub *var)
{
	(void)key;
	if (var->key_w)
		move_up(var);
	if (var->key_s)
		move_down(var);
	if (var->key_right)
		move_right(var, var->move_speed);
	if (var->key_left)
		move_left(var, var->move_speed);
	if (var->key_d)
		move_right_(var);
	if (var->key_a)
		move_left_(var);
	if (var->key_esc)
		exit(0);
	return (0);
}
