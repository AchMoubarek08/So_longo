/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:25:51 by amoubare          #+#    #+#             */
/*   Updated: 2022/06/21 05:16:24 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map(char *filename, int height)
{
	char	**map;
	char	*str;
	int		j;
	int		fd;
	char	*temp;

	fd = open(filename, O_RDONLY);
	j = 0;
	map = (char **)malloc(sizeof(char *) * height + 1);
	if (fd == -1)
		ft_error("Wrong file");
	str = get_next_line(fd);
	while (height--)
	{
		map[j] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
		j++;
	}
	map[j] = NULL;
	return (map);
}

void	check_map(char **str, int height, int width)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i])
	{
		if (i == 0 || i == height)
			str_is_one(str[i]);
		else
			begin_end_one(str[i], width);
		i++;
	}
}

int	xclose(t_vars *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
	return (0);
}
