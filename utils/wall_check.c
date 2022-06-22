/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:50:29 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/20 19:16:45 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_first_line(t_cub *var)
{
	int	i;

	i = 0;
	while (var->map_t[0][i])
	{
		if (var->map_t[0][i] != '1' && var->map_t[0][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_west_walls(t_cub *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map_t[i])
	{
		j = 0;
		if (var->map_t[i][0] == ' ')
		{
			while (var->map_t[i][j] == ' ')
				j++;
			if (var->map_t[i][j] != '1')
				return (0);
		}
		else if (var->map_t[i][0] != ' ' && var->map_t[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_east_walls(t_cub *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var->map_t[i]);
	while (var->map_t[i])
	{
		if (var->map_t[i][len - 1] != '1' && var->map_t[i][len - 1] \
		!= '0' && var->map_t[i][len - 1] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_closed_spaces(t_cub *var)
{
	int	i;
	int	j;

	i = 0;
	var->lines = count_rows(var);
	if (!var->map_t || var->lines < 3)
		return (0);
	while (var->map_t[i])
	{
		j = 0;
		while (var->map_t[i][j])
		{
			if (var->map_t[i][j] == ' ' && ((i > 0 && var->map_t[i
						- 1][j] != '1' && var->map_t[i - 1][j] != ' ') || (j > 0
						&& var->map_t[i][j - 1] != '1' && var->map_t[i][j
						- 1] != ' ') || (i < var->lines - 1 && var->map_t[i
						+ 1][j] != '1' && var->map_t[i + 1][j] != ' ')
					|| (j < var->max_line - 1 && var->map_t[i][j + 1] != '1'
						&& var->map_t[i][j + 1] != ' ')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_south_wall(t_cub *var)
{
	int	i;
	int	j;

	i = var->lines - 1;
	j = 0;
	while (var->map_t[i][j])
	{
		if (var->map_t[i][j] != '1' && var->map_t[i][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}
