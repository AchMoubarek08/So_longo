#include "so_long.h"

int	count_argc(char *filename)
{
	int i;
    int fd;

    i = 0;
    fd = open(filename, O_RDONLY);
	char *temp = get_next_line(fd);
	while(temp)
	{
		i++;
		temp = get_next_line(fd);
	}
	return (i);
}

void ft_error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

char	*ft_strndup(char *str, unsigned int n)
{
	char				*new;
	unsigned int		i;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	while (i < n)
		new[i++] = *str++;
	new[n] = 0;
	return (new);
}