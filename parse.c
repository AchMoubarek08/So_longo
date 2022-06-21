/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:14:01 by amoubare          #+#    #+#             */
/*   Updated: 2022/06/21 05:19:13 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	str_is_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\n')
			ft_error("Map not closed from top or bottom.");
		i++;
	}
}

void	begin_end_one(char *str, int width)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || i == width - 1)
		{
			if (str[i] != '1')
				ft_error("Map not closed from the sides.");
		}
		i++;
	}
}

void	initialize_go(char **map, int height)
{
	int		i;
	t_count	count;

	count.p = 0;
	count.one = 0;
	count.zero = 0;
	count.c = 0;
	count.exit = 0;
	i = 0;
	check_items(map, height, count, i);
}

void	check_items(char **map, int height, t_count count, int i)
{
	int	j;

	while (height--)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				count.one++;
			else if (map[i][j] == 'P')
				count.p++;
			else if (map[i][j] == 'E')
				count.exit++;
			else if (map[i][j] == '0')
				count.zero++;
			else if (map[i][j] == 'C')
				count.c++;
			else if (map[i][j] != '\n')
				ft_error("invalid item");
			j++;
		}
		i++;
	}
	if (count.p != 1 || count.exit != 1 || count.c < 1)
		ft_error("minimum");
}
