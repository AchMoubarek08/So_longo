
#include "so_long.h"

void ft_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

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
			ft_error("lfog wla lte7t");
		i++;
	}
	*str++;
}

void	begin_end_one(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(i == 0 || i == 12)
		{
			if(str[i] != '1')
				ft_error("m7lola mn jnab");
		}
		i++;
	}
}

void	check_map(char **str)
{
	int i = 1;
	char *temp;
	while(str[i])
	{
		if(i == 1 || i == 5)
			str_is_one(str[i]);
		else
			begin_end_one(str[i]);
		temp = str[i];

		if(i > 1 && i != 5)
			if(strlen(str[i - 1]) != strlen(temp))
				ft_error("mamereb3ach");
		if(strlen(str[5]) != strlen(str[1]) - 1)
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

int main()
{
	char **str;
	int *fd;
	char *ptr;
	fd = malloc(4);
	*fd = open("map1.ber", O_RDONLY, 777);
	str = map(fd);
	check_items(str);
	check_map(str);
	return(0);
}
