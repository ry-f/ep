/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 09:33:14 by exam              #+#    #+#             */
/*   Updated: 2015/03/25 10:09:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int			ft_strncmp(char *a, char *b, int c)
{
	while (*a && *b && c && *a == *b)
	{
		a++;
		b++;
		c--;
	}
	return (c != 0);
}

int			match_all(char **av, char *t, int len)
{
	int		i = 1;
	int		y = 0;

	while (av[i])
	{
		y = 0;
		while (av[i][y])
		{
			if (ft_strncmp(av[i] + y, t, len) == 0)
				break;
			y++;
		}
		if (!av[i][y])
			return (0);
		i++;
	}
	return (1);
}

int			get_max_len(char **av, char *t)
{
	int		len = 0;

	while (match_all(av, t, len))
	{
		len++;
	}
	return (len - 1);
}

int			main(int ac, char **av)
{
	int		i = 1;
	int		y = 0;
	int		maxlen = -1;
	char	*start = 0;
	int		len;

	(void)ac;
	while (av[i])
	{
		y = 0;
		while (av[i][y])
		{
			len = get_max_len(av, av[i] + y);
			if (len > maxlen)
			{
				maxlen = len;
				start = av[i] + y;
			}
			y++;
		}
		i++;
	}
	if (start)
		write(1, start, maxlen);
	write(1, "\n", 1);
	return (0);
}
