/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:33:00 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/14 14:33:49 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int key, t_cub *var)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		var->key_w = 1;
	else if (key == K_A)
		var->key_a = 1;
	else if (key == K_S)
		var->key_s = 1;
	else if (key == K_D)
		var->key_d = 1;
	else if (key == K_AR_L)
		var->key_left = 1;
	else if (key == K_AR_R)
		var->key_right = 1;
	return (0);
}

int	key_release(int key, t_cub *var)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		var->key_w = 0;
	else if (key == K_A)
		var->key_a = 0;
	else if (key == K_S)
		var->key_s = 0;
	else if (key == K_D)
		var->key_d = 0;
	else if (key == K_AR_L)
		var->key_left = 0;
	else if (key == K_AR_R)
		var->key_right = 0;
	return (0);
}
