/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:15:07 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/19 11:33:10 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_floor_color(char **tmp, t_cub *var)
{
	var->text.frgb.r = ft_atoi(tmp[0]);
	var->text.frgb.g = ft_atoi(tmp[1]);
	var->text.frgb.b = ft_atoi(tmp[2]);
}

void	put_ceilling_color(char **tmp, t_cub *var)
{
	var->text.crgb.r = ft_atoi(tmp[0]);
	var->text.crgb.g = ft_atoi(tmp[1]);
	var->text.crgb.b = ft_atoi(tmp[2]);
}
