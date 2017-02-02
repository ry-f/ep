/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 09:42:33 by exam              #+#    #+#             */
/*   Updated: 2015/04/01 09:48:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			checkchar(char *str, char c, int len)
{
	int		i;

	i = 0;
	while (str[i] && (i < len || len == -1))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!checkchar(av[1], av[1][i], i) && checkchar(av[2], av[1][i], -1))
				write(1, av[1] + i, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
