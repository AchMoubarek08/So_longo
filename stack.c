#include "so_long.h"

t_bool	stack_vide(t_element st)
{
	if (st == NULL)
		return (true);
	return (false);
}
void	print_stack(t_element st, int height)
{
	int i;

	i = 0;
	if (stack_vide(st))
	{
		printf("Rien a afficher, la stack est vide.\n");
		return ;
	}
	while (!stack_vide(st))
	{
		if(i == 13)
		{
			i = 0;
			printf("\n");
		}
		printf("[%c", st->name);
		printf(",%d", st->x);
		printf(",%d]", st->y);
		st = st->next;
		i++;
	}
	printf("\n");
}

void	push_stack(t_element *st, int x, int y, char n)
{
	element	*element;
	t_element tmp;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return ;
	element->x = x;
	element->y = y;
	element->name = n;
	tmp = *st;
	*st = element;
	element->next = tmp;
}

t_element	new_pile(void)
{
	return (NULL);
}

void	fill_stack(t_element *st, char **map, int height)
{
	int i;
	int j;


	i = 1;
	j = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '1')
				push_stack(st, (i - 1) * 60, j * 60, '1');
			else if(map[i][j] == 'P')
				push_stack(st, (i - 1) * 60, j * 60, 'P');
			else if(map[i][j] == 'E')
				push_stack(st, (i - 1) * 60, j * 60, 'E');
			else if(map[i][j] == '0')
				push_stack(st, (i - 1) * 60, j * 60, '0');
			else if(map[i][j] == 'C')
				push_stack(st, (i - 1) * 60, j * 60, 'C');
			else if(map[i][j] == '\n' || map[i][j] == '\0')
				break;
			j++;
		}
		i++;
	}
}