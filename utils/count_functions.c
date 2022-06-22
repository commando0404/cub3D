/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:00:59 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/20 20:01:49 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_len(t_cub *variables)
{
	int	i;

	i = 0;
	while (variables->map_t[i])
		i++;
	return (i);
}

int	count_comma(char *color)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (color[i])
		if (color[i++] == ',')
			count++;
	return (count);
}

int	count_rows(t_cub *var)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (var->str[i])
	{
		i++;
		j++;
	}
	return (j);
}

void	count_elements(t_cub *var)
{
	int		i;
	t_check	tmp;

	i = 0;
	tmp = (t_check){};
	while (i < 6)
	{
		if (!ft_strncmp(var->str[i], "NO", 2))
			tmp.n++;
		if (!ft_strncmp(var->str[i], "SO", 2))
			tmp.s++;
		if (!ft_strncmp(var->str[i], "EA", 2))
			tmp.e++;
		if (!ft_strncmp(var->str[i], "WE", 2))
			tmp.w++;
		if (!ft_strncmp(var->str[i], "F", 1))
			tmp.f++;
		if (!ft_strncmp(var->str[i], "C", 1))
			tmp.c++;
		i++;
	}
	if (tmp.n != 1 || tmp.s != 1 || tmp.e != 1 || tmp.w != 1 || tmp.f != 1
		|| tmp.c != 1)
		ft_error("Error\nMap config invalid\n");
}
