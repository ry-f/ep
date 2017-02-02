/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 09:30:03 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 09:41:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		put_char(char c)
{
	write(1, &c, 1);
}

void		put_word(char *str)
{
	while (*str && *str != ' ' && *str != '\t')
		write(1, str++, 1);
}

int			main(int ac, char **av)
{
	int		i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
			i++;
		i--;
		while (av[1][i] && i > 0)
		{
			while (av[1][i] != ' ' && av[1][i] != '\t' && i > 0)
				i--;
			put_word(av[1] + i + (i == 0 ? 0 : 1));
			if (i > 0)
				put_char(' ');
			while ((av[1][i] == ' ' || av[1][i] == '\t') && i > 0)
				i--;
		}
	}
	put_char('\n');
	return (0);
}
