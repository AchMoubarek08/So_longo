
#include "so_long.h"

void	str_is_one(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] != '1' && str[i] != '\n')
			ft_error("lfog wla lte7t");
		i++;
	}
}

void ft_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}
char	**map(int fd, int height)
{
	char **map;
	char *str;
	int i,j;
	i = 0;
	j = 1;
	map = malloc(400);
	str =  get_next_line(fd);
	while(j < height)
	{
		i = 0;
		map[j] = malloc(100);
		while(str[i])
		{
			map[j][i] = str[i];
			i++;
		}
		str =  get_next_line(fd);
		j++;
	}
	return(map);
}

void	begin_end_one(char *str)
{
	int i;
	int len;
	i = 0;
	len = ft_strlen(str) - 2;
	while(str[i])
	{
		if(i == 0 || i == len)
		{
			if(str[i] != '1')
				ft_error("m7lola mn jnab");
		}
		i++;
	}
}

int	count_argc(int fd)
{
	int i;
	char *str;

	i = 1;
	fd = open("map1.ber", O_RDONLY, 777);
	str =  get_next_line(fd);
	while(str && str[i])
	{
		i++;
		str =  get_next_line(fd);
	}
	return(i);
}

void	check_map(char **str, int height)
{
	int i = 1;
	char *temp;

	while(str[i])
	{
		if(i == 1 || i == height - 1)
			str_is_one(str[i]);
		else
			begin_end_one(str[i]);
		temp = str[i];
		if(i > 1 && i != height - 1)
			if(ft_strlen(str[i - 1]) != strlen(temp))
				ft_error("mamereb3ach");
		if(ft_strlen(str[height - 1]) != strlen(str[1]) - 1)
			ft_error("mamereb3ach");
		i++;
	}
}

void	check_items(char **str)
{
	int i;
	int j;
	s_count count;
	count.p = 0;
	count.one = 0;
	count.zero = 0;
	count.c = 0;
	count.exit = 0;

	j = 0;
	i = 1;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if(str[i][j] == '1')
				count.one++;
			else if(str[i][j] == 'P')
				count.p++;
			else if(str[i][j] == 'E')
				count.exit++;
			else if(str[i][j] == '0')
				count.zero++;
			else if(str[i][j] == 'C')
				count.c++;
			else if(str[i][j] != '\n')
				ft_error("item mkynch");
			j++;
		}
		i++;
	}
	if(count.p != 1 || count.exit != 1 || count.c < 1)
		ft_error("minimum");
}