/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mous_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:28:11 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:08:55 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mouse_move_left(int x, int y, int diff, t_cub *var)
{
	var->mouse.x = x;
	while (diff-- != 0)
		move_left(var, SENSITIVITY);
	if (x < ((int)(WIDTH_)))
	{
		mlx_mouse_move(var->mlx_win, (int)(WIDTH_ / 2), y);
		var->mouse.x = (int)(WIDTH_ / 2);
	}
}

void	mouse_move_right(int x, int y, int diff, t_cub *var)
{
	var->mouse.x = x;
	while (diff-- != 0)
		move_right(var, SENSITIVITY);
	if (x > (int)(WIDTH_))
	{
		mlx_mouse_move(var->mlx_win, \
						(int)(WIDTH_ / 2), \
						y);
		var->mouse.x = (int)(WIDTH_ / 2);
	}
}

int	mouse_move(int x, int y, t_cub *var)
{
	int	diff;

	mlx_mouse_hide();
	diff = abs(var->mouse.x - x);
	if (y < (int)(HEIGHT_) || y > (int)(HEIGHT_))
		mlx_mouse_move(var->mlx_win, x, (int)(HEIGHT_ / 2));
	if (x > var->mouse.x)
		mouse_move_right(x, y, diff, var);
	else if (x < var->mouse.x)
		mouse_move_left(x, y, diff, var);
	return (0);
}
