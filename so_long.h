
#ifndef     SO_LONG_H
# define    SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>

// typedef struct t_items
// {
//     int window[2];
//     s_element player;
//     s_element exit;
//     s_element *coin;
//     s_element *terre;
//     s_element *mur;
// }s_items;

typedef enum bool
{
	false,
	true
}t_bool;

typedef struct element
{
    char name;
    int x;
    int y;
    struct element *next;
}element, *t_element;

typedef struct t_count
{
    int p;
    int c ;
    int zero;
    int one;
    int exit;
}s_count;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
int	    ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_int_strchr(const char *s, int c);


t_bool      stack_vide(t_element st);
void        print_stack(t_element st, int height);
void        push_stack(t_element *st, int x, int y, char n);
t_element   new_pile(void);
void        fill_stack(t_element *st, char **map, int height);

void	    str_is_one(char *str);
void        ft_error(char *str);
void	    check_items(char **str);
void	    check_map(char **str, int height);
int	        count_argc(int fd);
void	    begin_end_one(char *str);
char	    **map(int fd, int height);

#endif