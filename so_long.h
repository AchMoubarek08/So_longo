
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


char	*ft_strdup(const char *s);
int	    ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
int		ft_int_strchr(const char *s, int c);

#endif