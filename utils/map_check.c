/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:32:48 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/18 23:19:31 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_max_line(t_cub *var)
{
	int	i;

	i = 6;
	var->max_line = ft_strlen(var->str[6]);
	while (var->str[i])
	{
		if ((int)ft_strlen(var->str[i]) > var->max_line)
			var->max_line = ft_strlen(var->str[i]);
		i++;
	}
	var->max_line += 1;
}
