/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:17:37 by amoubare          #+#    #+#             */
/*   Updated: 2022/06/15 02:39:53 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_item_position(char **str, char c)
{
	int	*tab;

	tab = malloc(8);
	tab[0] = 0;
	tab[1] = 0;
	while (str[tab[0]])
	{
		tab[1] = 0;
		while (str[tab[0]][tab[1]])
		{
			if (str[tab[0]][tab[1]] == c)
				return (tab);
			tab[1]++;
		}
		tab[0]++;
	}
	return (NULL);
}

void	swap_player(char **str, int dirc, int x, int y)
{
	if (dirc == 4)
	{
		str[x][y] = '0';
		str[x][y - 1] = 'P';
	}
	else if (dirc == 6)
	{
		str[x][y] = '0';
		str[x][y + 1] = 'P';
	}
	else if (dirc == 8)
	{
		str[x][y] = '0';
		str[x - 1][y] = 'P';
	}
	else if (dirc == 2)
	{
		str[x][y] = '0';
		str[x + 1][y] = 'P';
	}
}

void	*put_items_helper(t_vars mlx, int i, int j)
{
	int	k;
	int	z;

	if (mlx.map[i][j] == '0')
			mlx.img = mlx_xpm_file_to_image(mlx.ptr,
				"./0.xpm", &i, &j);
	else if (mlx.map[i][j] == '1')
		mlx.img = mlx_xpm_file_to_image(mlx.ptr,
				"./1.xpm", &i, &j);
	else if (mlx.map[i][j] == 'P')
		mlx.img = mlx_xpm_file_to_image(mlx.ptr,
				"./player_down.xpm", &i, &j);
	else if (mlx.map[i][j] == 'E')
		mlx.img = mlx_xpm_file_to_image(mlx.ptr,
				"./E.xpm", &i, &j);
	else if (mlx.map[i][j] == 'C')
		mlx.img = mlx_xpm_file_to_image(mlx.ptr,
				"./C.xpm", &i, &j);
	return (mlx.img);
}

void	put_items(t_vars mlx, int z, int k)
{
	int		i;
	int		j;

	i = 0;
	while (mlx.map[i])
	{
		j = 0;
		while (mlx.map[i][j])
		{
			mlx.img = put_items_helper(mlx, i, j);
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_vars		mlx;
	int			z;
	int			k;
	char		*filename;

	if (argc != 2)
		ft_error("Wrong number of args");
	filename = ft_strdup(argv[1]);
	check_filename(filename);
	mlx.h = count_argc(filename);
	mlx.map = map(filename, mlx.h);
	mlx.w = ft_strlen(mlx.map[0]) - 1;
	check_items(mlx.map, mlx.h);
	check_map(mlx.map, mlx.h, mlx.w);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, SIZE * mlx.w, SIZE * mlx.h, "so_long");
	put_items(mlx, z, k);
	mlx_key_hook(mlx.win, keyhook, &mlx);
	mlx_loop(mlx.ptr);
}
