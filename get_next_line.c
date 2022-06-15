/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:24:30 by amoubare          #+#    #+#             */
/*   Updated: 2022/06/15 00:13:09 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nadi(char **stock, char **ligne)
{
	char	*temp;
	int		x;

	x = ft_int_strchr(*stock, '\n') + 1;
	*ligne = ft_substr(*stock, 0, x);
	temp = *stock;
	*stock = ft_substr(*stock, x, ft_strlen(*stock));
	free(temp);
}

char	*ft_free(char **lost)
{
	if (*lost)
		free(*lost);
	*lost = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			i;
	char		buff[5];
	char		*ligne;
	static char	*stock;
	char		*temp;

	while (ft_int_strchr(stock, '\n') == -1)
	{
		i = read(fd, buff, 5);
		if (i == 0 || i == -1)
		{
			if (stock && stock[0] == '\0')
				ft_free(&stock);
			ligne = stock;
			stock = NULL;
			return (ligne);
		}
		buff[i] = '\0';
		temp = stock;
		stock = ft_strjoin(stock, buff);
		ft_free(&temp);
	}
	nadi(&stock, &ligne);
	return (ligne);
}
