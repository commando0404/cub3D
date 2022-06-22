/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fonctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:14:29 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 11:42:51 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) + (g << 8) | b);
}

int	ft_check_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (1);
	return (0);
}

int	ft_check_color(char *color)
{
	char	**temp;
	int		i;

	i = 0;
	if (!color || count_comma(color) != 2)
		return (1);
	temp = ft_split(color, ',');
	while (temp[i])
		i++;
	if (i < 3)
		return (1);
	i = 0;
	while (i < 3)
	{
		if (ft_check_isdigit(temp[i]))
			return (1);
		if (ft_atoi(temp[i]) > 255 || ft_atoi(temp[i]) < 0)
			return (1);
		i++;
	}
	free_(temp);
	return (0);
}
