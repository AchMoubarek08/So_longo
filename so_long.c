
#include "so_long.h"
void check_filename(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == '.')
			break;
		i++;
	}
	if(strcmp(str + i, ".ber") != 0)
		ft_error("Wrong file extension.");
}
int main(int argc, char *argv[])
{
	char **str;
	int fd;
	t_vars		mlx_vars;
	char *filename = ft_strdup(argv[1]);
	int height;
	check_filename(filename);
	mlx_vars.height = count_argc(filename);
	str = map(filename, mlx_vars.height);
	mlx_vars.width = ft_strlen(str[0]) - 1;
	check_items(str, mlx_vars.height);
	check_map(str, mlx_vars.height, mlx_vars.width);
	printf("%d\n", mlx_vars.width);
	printf("%d\n", mlx_vars.height);
	mlx_vars.mlx_ptr = mlx_init();
	mlx_vars.mlx_win = mlx_new_window(mlx_vars.mlx_ptr, imgsize * mlx_vars.width , imgsize * mlx_vars.height , "so_long");
	// mlx_key_hook(mlx_vars.mlx_win, key_hook, &mlx_vars);
	mlx_loop(mlx_vars.mlx_ptr);
	return(0);
}
