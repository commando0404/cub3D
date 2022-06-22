/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:55:32 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 15:55:00 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_texture(t_cub *var)
{
	var->y = -1;
	while (++var->y < 4)
	{
		var->texture[var->y] = malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (!var->texture[var->y])
			ft_perror("ERROR");
	}
	var->y = -1;
	while (++var->y < 4)
	{
		var->x = -1;
		while (++var->x < TEXHEIGHT * TEXWIDTH)
			var->texture[var->y][var->x] = 0;
	}
}

void	init_rot(t_cub *var, char c)
{
	if (c == 'N' || c == 'S')
	{
		var->dirx = -1;
		var->diry = 0;
		var->planex = 0;
		var->planey = 0.66;
		if (c == 'S')
		{
			var->dirx = 1;
			var->planey = -0.66;
		}
	}
	if (c == 'E' || c == 'W')
	{
		var->dirx = 0;
		var->diry = -1;
		var->planex = -0.66;
		var->planey = 0;
		if (c == 'E')
		{
			var->diry = 1;
			var->planex = 0.66;
		}
	}
}

void	init_direction(t_cub *var)
{
	int	i;
	int	j;

	i = 6;
	while (var->str[i])
	{
		j = 0;
		while (var->str[i][j])
		{
			if (var->str[i][j] == 'N')
				init_rot(var, 'N');
			else if (var->str[i][j] == 'S')
				init_rot(var, 'S');
			else if (var->str[i][j] == 'E')
				init_rot(var, 'E');
			if (var->str[i][j] == 'W')
				init_rot(var, 'W');
			j++;
		}
		i++;
	}
	free_(var->str);
}

void	init_default_value(t_cub *var)
{
	var->move_speed = 0.08;
	var->rot_speed = 0.9;
	var->dirx = -1.0;
	var->diry = 0.0;
	var->planex = 0.0;
	var->planey = 0.66;
	var->key_w = 0;
	var->key_a = 0;
	var->key_s = 0;
	var->key_d = 0;
	var->key_esc = 0;
	var->key_left = 0;
	var->key_right = 0;
	var->mouse.x = WIDTH_ / 2 ;
	var->mouse.y = HEIGHT_ / 2;
}

void	ft_init(t_cub *var)
{
	if (player_pos(&var) != 1)
		ft_error("ERROR\nPlayer does not found or duplicated\n");
	init_default_value(var);
	init_direction(var);
	while (++var->y < HEIGHT_)
	{
		var->x = -1;
		while (++var->x < WIDTH_)
			var->buf[var->y][var->x] = 0;
	}
	var->texture = (int **)malloc(sizeof(int *) * 4);
	if (!var->texture)
		ft_perror("ERROR");
	ft_init_texture(var);
}
