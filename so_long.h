
#ifndef     SO_LONG_H
# define    SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <mlx.h>
# define imgsize 50
# define left -1
# define right 1
# define up -1
# define down 1

typedef struct s_vars
{
	void			*ptr;
	void			*win;
	void			*img;
	char			**map;
	int				x;
	unsigned int	w;
	unsigned int	h;
}	t_vars;

typedef struct s_count
{
	int c;
    int p;
    int zero;
    int one;
    int exit;
}	t_count;

void	ft_putendl_fd(char *s, int fd);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
int	    ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_int_strchr(const char *s, int c);
void	str_is_one(char *str);
void	ft_error(char *str);
void	check_items(char **str, int height);
void	check_map(char **str, int height, int width);
int		count_argc(char *filename);
void	begin_end_one(char *str, int width);
char	**map(char *filename, int height);
char	*ft_strndup(char *str, unsigned int n);
void	check_filename(char *str);

#endif