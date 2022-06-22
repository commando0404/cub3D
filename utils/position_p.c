/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:33:14 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 15:50:30 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	player_pos(t_cub **var)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while ((*var)->map_t[i])
	{
		j = 0;
		while ((*var)->map_t[i][j])
		{
			if ((*var)->map_t[i][j] == 'N' || (*var)->map_t[i][j] == 'S'
				|| (*var)->map_t[i][j] == 'E' || (*var)->map_t[i][j] == 'W')
			{
				(*var)->posx = i;
				(*var)->posy = j;
				(*var)->map_t[i][j] = '0';
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
