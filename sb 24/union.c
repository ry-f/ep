/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 09:34:44 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 09:42:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_strcont(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

int			ft_stricont(char *str, char c, int i)
{
	while (--i >= 0)
		if (str[i] == c)
			return (1);
	return (0);
}

int			main(int ac, char **av)
{
	int		i;

	if (ac != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	i = -1;
	while (av[1][++i])
		if (!ft_stricont(av[1], av[1][i], i))
			ft_putchar(av[1][i]);
	i = -1;
	while (av[2][++i])
		if (!ft_strcont(av[1], av[2][i]) && !ft_stricont(av[2], av[2][i], i))
			ft_putchar(av[2][i]);
	ft_putchar('\n');
	return (0);
}
