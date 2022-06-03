
#include "so_long.h"

int	*get_item_position(char **str, char c)
{
	int	*tab;

	tab = malloc(8);
	tab[0] = 1;
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
void	swap_player(char **map, int dirc, int x, int y)
{
	if (dirc == 4)
	{
		map[x][y] = '0';
		map[x][y - 1] = 'P';
	}
	else if (dirc == 6)
	{
		map[x][y] = '0';
		map[x][y + 1] = 'P';
	}
	else if (dirc == 8)
	{
		map[x][y] = '0';
		map[x - 1][y] = 'P';
	}
	else if (dirc == 2)
	{
		map[x][y] = '0';
		map[x + 1][y] = 'P';
	}
}

void	move_right_left(t_vars *mlx, int *tab, int dir)
{
	int k;
	int z;
	if(mlx.map[tab[0]][tab[1] + dir] == 'E' && get_item_position(map, 'C') == NULL)
	{
			swap_player(mlx_vars->map, 2, tab[0], tab[1]);
			sleep(1);
			exit(EXIT_SUCCESS);
	}
	else if (mlx.map[tab[0]][tab[1] + dir] != 'E')
	{
		if(mlx.map[tab[0]][tab[1] + dir] != '1')
		{
			if(mlx.map[tab[0]][tab[1] + dir] == 'C')
			{
				mlx.map[tab[0]][tab[1]] = '0';
				mlx.map[tab[0]][tab[1] + dir] = 'P';
				mlx->coins--;
			}
			else
			{
				mlx.map[tab[0]][tab[1]] = '0';
				mlx.map[tab[0]][tab[1] + dir] = '1';
			}
		}
	}
}

void move_up_down(t_vars *mlx, int *tab, int dir)
{
	if(mlx.map[tab[0]][tab[1] + dir] == 'E' && get_item_position(map, 'C') == NULL)
	{
			mlx.map[tab[0]][tab[1]] = '0';
			mlx.map[tab[0]][tab[1] + dir] = 'P';
			sleep(1);
			exit(EXIT_SUCCESS);
	}
	else if (mlx.map[tab[0] + dir][tab[1]] != 'E')
	{
		if(mlx.map[tab[0] + dir][tab[1]] != '1')
		{
			if(mlx.map[tab[0] + dir][tab[1]] == 'C')
			{
				mlx.map[tab[0]][tab[1]] = '0';
				mlx.map[tab[0] + dir][tab[1]] = 'P';
				mlx->coins--;
			}
			else
			{
				mlx.map[tab[0]][tab[1]] = '0';
				mlx.map[tab[0] + dir][tab[1]] = '1';
			}
		}
	}
}

int keyhook(int keycode, t_vars *mlx)
{
	int	*tab;
	int	k;
	int	z;

	tab = get_player_position(mlx_vars->map, 'P');
	if (keycode == 2)
		move_right_left(mlx, tab, right);
	else if (keycode == 0)
		move_right_left(mlx, tab, left);
	else if (keycode == 1)
		move_up_down(mlx, tab, down);
	else if (keycode == 13)
		move_up_down(mlx, tab, up);
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
int main(int argc, char *argv[])
{
	t_vars		mlx;
	int coins;
	char *filename = ft_strdup(argv[1]);
	check_filename(filename);
	mlx.h = count_argc(filename);
	mlx.map = map(filename, mlx.h);
	mlx.w = ft_strlen(mlx.map[0]) - 1;
	mlx.coins = check_items(mlx.map, mlx.h);
	check_map(mlx.map, mlx.h, mlx.w);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, imgsize * mlx.w, imgsize * mlx.h, "so_long");
	mlx_key_hook(mlx.win, keyhook, &mlx);
	mlx_loop(mlx.ptr);
	return(0);
}
