/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 10:29:29 by exam              #+#    #+#             */
/*   Updated: 2015/03/25 10:48:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void		count_island(char **i, int x, int y, char c)
{
	if (y < 0 || x < 0 || !i[y] || !i[y][x] || i[y][x] != 'X')
		return ;
	i[y][x] = c;
	count_island(i, x + 1, y, c);
	count_island(i, x - 1, y, c);
	count_island(i, x, y + 1, c);
	count_island(i, x, y - 1, c);
}

void		sefsrg(char **i)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	c = '0';
	while (i[y])
	{
		x = 0;
		while (i[y][x])
		{
			if (i[y][x] == 'X')
				count_island(i, x, y, c++);
			write(1, i[y] + x, 1);
			x++;
		}
		y++;
		if (x > 0)
			write(1, "\n", 1);
	}
}

char		**cread(int fd);

int			main(int ac, char **av)
{
	int		fd;
	char	**a;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd != -1)
		{
			a = cread(fd);
			close(fd);
			if (a != 0)
			{
				sefsrg(a);
				return (0);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
