
#include "so_long.h"

char	**map(int *fd)
{
	char **map;
	char *str;
	int i,j;
	i = 0;
	j = 1;
	map = malloc(400);
	while(j < 6)
	{
		i = 0;
		str =  get_next_line(*fd);
		map[j] = malloc(400);
		while(str[i])
		{
			map[j][i] = str[i];
			i++;
		}
		j++;
	}
	return(map);
}

void	str_is_one(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] != '1' && str[i] != '\n')
		{
			printf("zeubi\n");
			exit(1);
		}
		i++;
	}
}

void	check_map(char **str)
{
	int i = 1;
	str_is_one(str[i]);
	str_is_one(str[5]);
}

int main()
{
	char **str;
	int *fd;
	char *ptr;
	fd = malloc(4);
	*fd = open("map1.ber", O_RDONLY, 777);
	str = map(fd);
	check_map(str);
	return(0);
}
