/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:47:29 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/22 09:42:13 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_image(t_cub *var, int *texture, char *path, t_img *img)
{
	if (open(path, O_RDONLY) < 0)
		ft_perror("Error\nTexture");
	img->img = mlx_xpm_file_to_image(var->mlx, path, &img->img_width,
			&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
			&img->endian);
	var->y = -1;
	while (++var->y < img->img_height)
	{
		var->x = -1;
		while (++var->x < img->img_width)
			texture[img->img_width * var->y + var->x] = img->data[img->img_width
				* var->y + var->x];
	}
	mlx_destroy_image(var->mlx, img->img);
}

void	load_texture(t_cub *var)
{
	t_img	img;

	load_image(var, var->texture[0], var->text.n_tex, &img);
	load_image(var, var->texture[1], var->text.s_tex, &img);
	load_image(var, var->texture[2], var->text.e_tex, &img);
	load_image(var, var->texture[3], var->text.w_tex, &img);
}
