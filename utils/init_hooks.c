/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:30:43 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/20 20:13:42 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	exit_game(void)
{
	exit(EXIT_SUCCESS);
}

static int	update(t_cub *var)
{
	void	*img;
	int		w;
	int		h;

	calc(var);
	draw(var);
	key_update(69, var);
	ft_draw_player(var, var->posx, var->posy);
	img = mlx_xpm_file_to_image(var->mlx, "./textures/Crosshair.xpm", &w, \
			&h);
	mlx_put_image_to_window(var->mlx, var->mlx_win, img, (WIDTH_ / 2) - 20, \
			(HEIGHT_ / 2) - 20);
	return (0);
}

void	init_hooks(t_cub *var)
{
	mlx_loop_hook(var->mlx, &update, var);
	mlx_hook(var->mlx_win, X_EVENT_KEY_PRESS, 0, &key_press, var);
	mlx_hook(var->mlx_win, X_EVENT_KEY_RELEASE, 0, &key_release, var);
	mlx_hook(var->mlx_win, 6, 0x40, mouse_move, var);
	mlx_hook(var->mlx_win, 17, 1L << 0, exit_game, var);
}
