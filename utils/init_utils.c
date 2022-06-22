/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:41:57 by ahkecha           #+#    #+#             */
/*   Updated: 2022/06/19 10:17:45 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_search(char *str, int search_char)
{
	int	i;

	i = 0;
	while (str[i++])
		if ((int)str[i] == search_char)
			return (1);
	return (0);
}

size_t	count_parts(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
