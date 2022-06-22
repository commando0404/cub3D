/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:26:34 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/20 20:08:10 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	build_map_(t_cub *var)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	var->map_t = malloc(sizeof(char *) * (count_rows(var) + 1));
	if (!var->map_t)
		ft_perror("ERROR");
	get_max_line(var);
	while (var->str[i])
	{
		var->map_t[j] = malloc(sizeof(char) * var->max_line + 1);
		if (!var->map_t[j])
			ft_perror("ERROR");
		ft_memset(var->map_t[j], ' ', var->max_line);
		var->map_t[j][var->max_line] = '\0';
		ft_memmove(var->map_t[j], var->str[i], ft_strlen(var->str[i]));
		j++;
		i++;
	}
	var->map_t[j] = NULL;
}

int	build_map(t_cub *var)
{
	int	i;
	int	j;

	i = 5;
	if (!var->str[6])
		ft_error("ERROR\nInvalid Map ...\n");
	while (var->str[++i])
	{
		j = -1;
		while (var->str[i][++j])
			if (var->str[i][j] != ' ' && var->str[i][j] != '\t'
				&& var->str[i][j] != 'N' && var->str[i][j] != 'S'
				&& var->str[i][j] != 'E' && var->str[i][j] != 'W'
				&& var->str[i][j] != '1' && var->str[i][j] != '0')
				ft_error("ERROR\nInvalid Map ...\n");
	}
	build_map_(var);
	return (0);
}
