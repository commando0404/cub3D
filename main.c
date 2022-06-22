/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:56:49 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 10:19:21 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	var;

	var = (t_cub){};
	if (ac == 2)
	{
		ft_check_map(av[1], &var);
		ft_init(&var);
		var.mlx = mlx_init();
		var.mlx_win = mlx_new_window(var.mlx, WIDTH_, HEIGHT_, "cub3D");
		load_texture(&var);
		var.img.img = mlx_new_image(var.mlx, WIDTH_, HEIGHT_);
		var.img.data = (int *)mlx_get_data_addr(var.img.img, &var.img.bpp,
				&var.img.size_l, &var.img.endian);
		init_hooks(&var);
		mlx_loop(var.mlx);
	}
	else
		ft_error("ERROR\nInvalid input ...\n");
}
