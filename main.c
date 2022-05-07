
#include "so_long.h"

int main()
{
	char **str;
	int fd;
	char *ptr;
	int height;
	fd = open("map1.ber", O_RDONLY, 777);
	height = count_argc(fd);
	str = map(fd, height);
	check_items(str);
	check_map(str, height);
	t_element elem;
	elem = new_pile();
	fill_stack(&elem, str, height);
	print_stack(elem, height);
	return(0);
}
