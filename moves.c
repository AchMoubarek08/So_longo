/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:41:45 by amoubare          #+#    #+#             */
/*   Updated: 2022/06/18 23:09:43 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_vars *mlx, int *tab)
{
	int		k;
	int		z;

	if (mlx->map[tab[0]][tab[1] + 1] != 49)
	{
		if (mlx->map[tab[0]][tab[1] + 1] != 69)
		{
			swap_player(mlx->map, 6, tab[0], tab[1]);
			mlx->img = mlx_xpm_file_to_image(mlx->ptr, "./0.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img, (tab[1]) * 50, (tab[0]) * 50);
			mlx->img = mlx_xpm_file_to_image(mlx->ptr, "./player_right.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img, (tab[1] + 1) * 50, (tab[0]) * 50);
			mlx->x++;
			printf("%d\n", mlx->x);
		}
		else if (get_item_position(mlx->map, 'C') == NULL
			&& mlx->map[tab[0]][tab[1] + 1] == 69)
			exit(EXIT_SUCCESS);
	}
}

void	move_left(t_vars *mlx, int *tab)
{
	int		k;
	int		z;

	if (mlx->map[tab[0]][tab[1] - 1] != 49)
	{
		if (mlx->map[tab[0]][tab[1] - 1] != 69)
		{
			swap_player(mlx->map, 4, tab[0], tab[1]);
			mlx->img = mlx_xpm_file_to_image(mlx->ptr, "./0.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img, (tab[1]) * 50, tab[0] * 50);
			mlx->img = mlx_xpm_file_to_image(mlx->ptr, "./player_left.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img, (tab[1] - 1) * 50, tab[0] * 50);
			mlx->x++;
			printf("%d\n", mlx->x);
		}
		else if (get_item_position(mlx->map, 'C') == NULL
			&& mlx->map[tab[0]][tab[1] - 1] == 69)
			exit(EXIT_SUCCESS);
	}
}

void	move_down(t_vars *mlx, int *tab)
{
	int		k;
	int		z;

	if (mlx->map[tab[0] + 1][tab[1]] != 49)
	{
		if (mlx->map[tab[0] + 1][tab[1]] != 69)
		{
			swap_player(mlx->map, 2, tab[0], tab[1]);
			mlx->img = mlx_xpm_file_to_image(mlx->ptr, "./0.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img, (tab[1]) * 50, (tab[0]) * 50);
			mlx->img = mlx_xpm_file_to_image(mlx->ptr, "./player_down.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img, (tab[1]) * 50, (tab[0] + 1) * 50);
			mlx->x++;
			printf("%d\n", mlx->x);
		}
		else if (get_item_position(mlx->map, 'C') == NULL
			&& mlx->map[tab[0] + 1][tab[1]] == 69)
			exit(EXIT_SUCCESS);
	}
}

void	move_up(t_vars *mlx, int *tab)
{
	int		k;
	int		z;

	if (mlx->map[tab[0] - 1][tab[1]] != 49)
	{
		if (mlx->map[tab[0] - 1][tab[1]] != 69)
		{
			swap_player(mlx->map, 8, tab[0], tab[1]);
			mlx->img = mlx_xpm_file_to_image(mlx->ptr, "./0.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img, (tab[1]) * 50, tab[0] * 50);
			mlx->img = mlx_xpm_file_to_image(mlx->ptr, "./player_up.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img, (tab[1]) * 50, (tab[0] - 1) * 50);
			mlx->x++;
			printf("%d\n", mlx->x);
		}
		else if (get_item_position(mlx->map, 'C') == NULL
			&& mlx->map[tab[0] - 1][tab[1]] == 69)
			exit(EXIT_SUCCESS);
	}
}

int	keyhook(int keycode, t_vars *mlx)
{
	int	*tab;
	int	k;
	int	z;

	tab = get_item_position(mlx->map, 'P');
	if (keycode == 124 || keycode == 2)
		move_right(mlx, tab);
	else if (keycode == 123 || keycode == 0)
		move_left(mlx, tab);
	else if (keycode == 125 || keycode == 1)
		move_down(mlx, tab);
	else if (keycode == 126 || keycode == 13)
		move_up(mlx, tab);
	else if (keycode == 53)
		exit(0);
	free(tab);
	return (0);
}
