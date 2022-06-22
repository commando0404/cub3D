/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkecha <ahkecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:07:54 by oabdelha          #+#    #+#             */
/*   Updated: 2022/06/20 15:45:03 by ahkecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	extension(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s1 = ft_strrchr(s1, '.');
	if (!s1)
		return (1);
	while (s2[i])
	{
		if (s1[i] != s2[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	ft_check_validation_of_map(char **str)
{
	int		i;
	char	**temp;

	i = -1;
	while (++i < 6)
	{
		temp = ft_split(str[i], 32);
		if (count_parts(temp) != 2)
			ft_error("ERROR\nInvalid element\n");
		if (temp[0] && check_orientation(temp[0]))
		{
			if (temp[1] && extension(temp[1], ".xpm"))
				ft_error("ERROR\nInvalid texture ...\n");
			else if (!temp[1])
				ft_error("Error\nTexture path not found\n");
		}
		else if (!check_floor_ceilling(temp[0]))
		{
			if (ft_check_color(temp[1]))
				ft_error("ERROR\nInvalid color ...\n");
		}
		free_(temp);
	}
	return (0);
}

void	get_floor_and_ceilling(t_cub *var)
{
	int		i;
	char	**tmp;

	i = 0;
	while (var->str[i] && i < 6)
	{
		if (var->str[i][0] == 'F' && var->str[i][1] == ' ')
		{
			tmp = ft_split(&var->str[i][2], ',');
			put_floor_color(tmp, var);
			free_(tmp);
		}
		else if (var->str[i][0] == 'C' && var->str[i][1] == ' ')
		{
			tmp = ft_split(&var->str[i][2], ',');
			put_ceilling_color(tmp, var);
			free_(tmp);
		}
		i++;
	}
}

void	get_textures(t_cub *var)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (var->str[i] && var->str[i][0] == 'N' && var->str[i][1] == 'O' &&
			(var->str[i][2] == ' '))
			ft_skip_espace_and_fill(var, &i, &var->text.n_tex);
		if (var->str[i] && var->str[i][0] == 'S' && var->str[i][1] == 'O' &&
			(var->str[i][2] == ' '))
			ft_skip_espace_and_fill(var, &i, &var->text.s_tex);
		if (var->str[i] && var->str[i][0] == 'E' && var->str[i][1] == 'A' &&
			(var->str[i][2] == ' '))
			ft_skip_espace_and_fill(var, &i, &var->text.e_tex);
		if (var->str[i] && var->str[i][0] == 'W' && var->str[i][1] == 'E' &&
			(var->str[i][2] == ' '))
			ft_skip_espace_and_fill(var, &i, &var->text.w_tex);
		i++;
	}
	get_floor_and_ceilling(var);
}

void	ft_check_map(char *map, t_cub *var)
{
	var->fd = open(map, O_RDONLY);
	if (extension(map, ".cub") || var->fd == -1)
		ft_error("ERROR\nFile doesn't found or extention Invalid\n");
	while (404)
	{
		var->line = get_line(var->fd);
		if (!var->line)
			break ;
		check_tab(var->line);
		var->helper = var->all_line;
		if (!var->helper)
			var->helper = ft_strdup("");
		var->all_line = ft_strjoin(var->helper, var->line);
		free(var->line);
		free(var->helper);
	}
	map_checks_(var, map);
}
