
#include "so_long.h"

void	str_is_one(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] != '1' && str[i] != '\n')
			ft_error("Map not closed from top or bottom.");
		i++;
	}
}

void	begin_end_one(char *str, int width)
{
	int i;
	i = 0;
	while(str[i])
	{
		if(i == 0 || i == width - 1)
		{
			if(str[i] != '1')
				ft_error("Map not closed from the sides.");
		}
		i++;
	}
}

void	check_items(char **str, int height)
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
	i = 0;
	while(height--)
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
				ft_error("Item not found.");
			j++;
		}
		i++;
	}
	if(count.p != 1 || count.exit != 1 || count.c < 1)
		ft_error("Missing item(s).");
}