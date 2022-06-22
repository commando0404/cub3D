/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:04:28 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/20 20:01:49 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_newline(t_cub *var, char *map)
{
	char	*tmp;
	int		fd;

	fd = open(map, O_RDONLY);
	var->skip_lines = 0;
	while (1)
	{
		tmp = get_line(fd);
		if (!tmp)
			return ;
		if (tmp && (!ft_strncmp(tmp, "1", 1) || !ft_strncmp(tmp, " ", 1)))
			break ;
		var->skip_lines++;
		free(tmp);
	}
	free(tmp);
}

int	check_newline2(t_cub *var, char *map)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(map, O_RDONLY);
	while (i++ < var->skip_lines)
	{
		tmp = get_line(fd);
		free(tmp);
	}
	while (404)
	{
		tmp = get_line(fd);
		if (!tmp)
			break ;
		if (tmp[0] == '\n')
			return (0);
		free(tmp);
	}
	free(tmp);
	return (1);
}

void	check_tab(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			ft_error("Error\nInvalid whitespaces\n");
		i++;
	}
}

void	map_checks_(t_cub *var, char *map)
{
	check_newline(var, map);
	if (!check_newline2(var, map))
		ft_error("ERROR\nInvalid Map (empty line)\n");
	if (!var->all_line)
		ft_error("ERROR\nInvalid Map ...");
	var->str = ft_split(var->all_line, '\n');
	count_elements(var);
	ft_check_validation_of_map(var->str);
	get_textures(var);
	build_map(var);
	if (!check_closed_spaces(var) || !check_first_line(var) \
	|| !check_east_walls(var) || !check_west_walls(var) \
	|| !check_south_wall(var))
		ft_error("ERROR\nInvalid Map (must be surrounded by walls)\n");
}
