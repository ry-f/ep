/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:08:30 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 09:12:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		pstr(char *c)
{
	while (*c)
		write(1, c++, 1);
}

int			main(int ac, char **av)
{
	int		i;
	int		y;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	y = 0;
	i = 0;
	while (av[1][y])
	{
		while (av[2][i] != av[1][y] && av[2][i])
			i++;
		if (!av[2][i])
			break;
		y++;
	}
	if (!av[1][y])
		pstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
