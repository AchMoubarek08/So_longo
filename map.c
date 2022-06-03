
#include "so_long.h"

char	**map(char *filename, int height)
{
	char **map;
	char *str;
	int j;
    int fd = open(filename, O_RDONLY);
	j = 0;
	map = (char **)malloc(sizeof(char * ) * height + 1);
    if(fd == -1)
        ft_error("Wrong file");
    str =  get_next_line(fd);
	while(str)
	{
		map[j] = ft_strdup(str);
		str = get_next_line(fd);
		j++;
	}
	if(str)
	{
		map[++j] = ft_strndup(str, ft_strlen(str));
	}
	map[++j] = NULL;
	return(map);
}

void	check_map(char **str, int height, int width)
{
	int i = 0;
	char *temp;
	int g = height;
	while(g--)
	{
		if(i == 0 || i == height)
			str_is_one(str[i]);
		else
			begin_end_one(str[i], width);
		i++;
	}

}