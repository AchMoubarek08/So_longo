
#include "so_long.h"

int main()
{
	char **str;
	int fd;
	fd = open("map1.ber", O_RDONLY, 777);
	*str = get_next_line(fd);
	printf("%s\n", *str);
	return(0);
}
