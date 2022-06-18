/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:14:21 by amoubare          #+#    #+#             */
/*   Updated: 2022/06/18 23:48:33 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_filename(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		i++;
	}
	if (strcmp(str + i, ".ber") != 0)
		ft_error("Wrong file extension.");
}

int	count_argc(char *filename)
{
	int		i;
	int		fd;
	char	*str;
	char	*temp;

	i = 0;
	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	temp = str;
	while (str)
	{	
		str = get_next_line(fd);
		free(str);
		i++;
	}
	free(temp);
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
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
