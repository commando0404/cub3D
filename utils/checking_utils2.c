/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:10:41 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/19 10:17:06 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_orientation(char *str)
{
	return ((!ft_strncmp(str, NORTH, ft_strlen(str)) \
		|| !ft_strncmp(str, SOUTH, ft_strlen(str))) \
		|| (!ft_strncmp(str, WEST, ft_strlen(str)) \
		|| !ft_strncmp(str, EAST, ft_strlen(str))));
}

int	check_floor_ceilling(char *str)
{
	if (ft_strncmp(str, F_CO, ft_strlen(str)) \
	&& ft_strncmp(str, C_CO, ft_strlen(str)))
		ft_error("ERROR\nInvalid identifier ...");
	return (0);
}

void	ft_skip_espace_and_fill(t_cub *var, int *i, char **str)
{
	int	j;

	j = 3;
	while (var->str[*i][j])
	{
		if (var->str[*i][j] != ' ')
			break ;
		j++;
	}
	*str = ft_substr(var->str[*i], j, (ft_strlen(var->str[*i]) - j));
}
